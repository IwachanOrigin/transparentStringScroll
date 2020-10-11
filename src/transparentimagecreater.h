/**
 * @copyright Copyright (c) Yuji Iwanaga
 * @date 19th Sep. 2020
 */

#ifndef TRANSPARENTIMAGECREATER_H
#define TRANSPARENTIMAGECREATER_H

#include <QImage>
#include <QObject>
#include <stdint.h>

class TransparentImageCreater : public QObject
{
    Q_OBJECT

public:
    explicit TransparentImageCreater();
    ~TransparentImageCreater();

    void setImageWidth(const int width) { mImageWidth = width; }
    void setImageHeight(const int height) { mImageHeight = height; }

    QImage generate();

private:
    int mImageWidth;
    int mImageHeight;
};

#endif
