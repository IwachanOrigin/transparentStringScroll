/**
 * @copyright Copyright (c) Yuji Iwanaga
 * @date 19th Sep. 2020
 */

#include "transparentimagecreater.h"

#include <QFont>
#include <QImage>
#include <QPainter>

TransparentImageCreater::TransparentImageCreater()
    : mImageWidth(0)
    , mImageHeight(0)
{
}

TransparentImageCreater::~TransparentImageCreater()
{
}

QImage TransparentImageCreater::generate()
{
    QImage image(QSize(mImageWidth, mImageHeight), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.setBrush(QBrush(QColor(0, 0, 0, 0)));
    painter.fillRect(QRectF(0, 0, mImageWidth, mImageHeight), QColor(0, 0, 0, 0));    
    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter.end();
    return image;
}
