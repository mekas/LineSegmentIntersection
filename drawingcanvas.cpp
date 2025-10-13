#include "drawingcanvas.h"

DrawingCanvas::DrawingCanvas(QWidget *parent)  {
    // Set a minimum size for the canvas
    setMinimumSize(400, 300);
    // Set a solid background color
    setStyleSheet("background-color: white; border: 1px solid gray;");
}

void DrawingCanvas::clearPoints(){
    m_points.clear();
    // Trigger a repaint to clear the canvas
    update();
}

void DrawingCanvas::paintLines(){
    /* Todo
     * Implement lines drawing per even pair

    QPainter painter(this);

    // Create a QPen to define the line's properties (color, width, style).
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4); // 4-pixel wide line
    pen.setStyle(Qt::SolidLine);

    // Set the painter's pen to our custom pen.
    painter.setPen(pen);

    // Draw the line. The coordinates are relative to the top-left
    // corner of the widget (0, 0). The line goes from (50, 50)
    // to (350, 250).
    painter.drawLine(50, 50, 350, 250);
    */
}

void DrawingCanvas::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set up the pen and brush for drawing the points
    QPen pen(Qt::blue, 5);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::blue));

    // Draw a small circle at each stored point
    for (const QPoint& point : m_points) {
        painter.drawEllipse(point, 3, 3);
    }
}

void DrawingCanvas::mousePressEvent(QMouseEvent *event) {
    // Add the mouse click position to our vector of points
    m_points.append(event->pos());
    // Trigger a repaint
    update();
}


