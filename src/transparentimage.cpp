
#include "transparentimage.h"
#include "transparentimagecreater.h"
#include "stringimagecreater.h"

#include <Qimage>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QFontMetrics>
#include <QString>
#include <QFont>

TransparentImage::TransparentImage(QWidget *parent)
    : QMainWindow(parent)
	, ui(new Ui::TransparentImageClass)
    , mGraphicsScene(new QGraphicsScene(this))
	, mMovingAmount(0.0)
    , mScrollPos(0.0)
    , mWindowWidth(1280)
    , mWindowHeight(720)
{
    ui->setupUi(this);

	/* init moving amount. */
    mMovingAmount = 0.1;

	/* set transparent window. */
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_NoSystemBackground);
	setAttribute(Qt::WA_TranslucentBackground);
	setAutoFillBackground(true);

	/* create bg image. */
	TransparentImageCreater *tic = new TransparentImageCreater();
	tic->setImageWidth(mWindowWidth);
	tic->setImageHeight(mWindowHeight);
	QImage bg = tic->generate();
	delete tic;

	/* set bg image. */
	mBgImage = bg;
	mBgImage = mBgImage.convertToFormat(QImage::Format_RGBA8888);
	int w = mBgImage.width();
	int h = mBgImage.height();
	setFixedSize(w, h);

	/* set scene */
    mGraphicsScene->setSceneRect(0, 0, mWindowWidth, mWindowHeight);

    /* init scroll pos. */
	mScrollPos = mWindowWidth;

	/* create foreground image */
	mFont = QFont("Times", 48);
	QFontMetrics fm(mFont);
	StringImageCreater *strImageCreater = new StringImageCreater();
	QString str = "Test Message";
	int width = fm.width(str);
	strImageCreater->setText(str);
	strImageCreater->setImageHeight(64);
	strImageCreater->setImageWidth(width);
	strImageCreater->setFont(mFont);
	QImage dispImage = strImageCreater->generate();
	mStrImg = new QGraphicsPixmapItem(QPixmap::fromImage(dispImage));
	mStrImg->setPos(mScrollPos, mWindowHeight / 2);
	mStrImg->setZValue(1);
	mGraphicsScene->addItem(mStrImg);

	/* set graphics view */
	QGraphicsView *graphicsView = new QGraphicsView(this);
	graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	graphicsView->setStyleSheet("background: transparent");
	graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	graphicsView->setScene(mGraphicsScene);
	ui->centralWidget->layout()->addWidget(graphicsView);

}

TransparentImage::~TransparentImage()
{
	delete ui;
}

void TransparentImage::paintEvent(QPaintEvent *)
{
	if (mScrollPos < 0) {
		mScrollPos = mWindowWidth;
	}
	mScrollPos -= mMovingAmount;
	mStrImg->setPos(mScrollPos, mWindowHeight / 2);
	update();
}
