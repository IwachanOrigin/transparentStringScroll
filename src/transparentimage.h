
#ifndef TRANSPARENTIMAGE_H
#define TRANSPARENTIMAGE_H

#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>

#include "ui_transparentimage.h"

class QGraphicsScene;
class QGraphicsPixmapItem;
class QImage;
class QString;
class QFont;

class TransparentImage : public QMainWindow
{
    Q_OBJECT

public:
    explicit TransparentImage(QWidget *parent = Q_NULLPTR);
	~TransparentImage();

protected:
	void paintEvent(QPaintEvent *);

private:
    Ui::TransparentImageClass *ui;

	QGraphicsScene *mGraphicsScene;
	QGraphicsPixmapItem *mStrImg;
	QImage mBgImage;
	QFont mFont;
    int mWindowWidth;
    int mWindowHeight;
	double mScrollPosPeriod;
	double mMovingAmount;
	double mScrollPos;
};

#endif // TRANSPARENTIMAGE_H
