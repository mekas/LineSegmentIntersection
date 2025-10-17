#ifndef DRAWINGCANVAS_H
#define DRAWINGCANVAS_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include <iostream>
#include <iomanip>
#include <QPixmap>

using namespace std;

class DrawingCanvas : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingCanvas(QWidget *parent = nullptr);

    // Slot to clear all points from the canvas
    void clearPoints();
    void paintLines();
    void segmentDetection();

protected:
    // Overridden method to handle painting on the widget
    void paintEvent(QPaintEvent *event) override;

    // Overridden method to handle mouse clicks
    void mousePressEvent(QMouseEvent *event) override;

private:
    // A vector to store all the points drawn by the user
    QVector<QPoint> m_points;

    bool isPaintLinesClicked = false;
};
#endif // DRAWINGCANVAS_H
