#ifndef MYPAINTER_H
#define MYPAINTER_H
#include <QQuickPaintedItem>
#include <QPointF>

class QPainter;

class MyPaniter : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QPoint originCoord READ getOriginCoord WRITE setOriginCoord NOTIFY updateSignal)
    Q_PROPERTY(int rote READ getRote WRITE setRote NOTIFY updateSignal)
    Q_PROPERTY(int showScale READ showScale WRITE setShowScale NOTIFY updateSignal)
public:
    MyPaniter(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;

private:
    void drawCoordSys(QPainter *painter);
    void calScalesPoint(qreal len, QVector<QPoint>& scale_points, bool is_h = true);
    void drawScalesPoints(QPainter *painter, const QVector<QPoint>& scale_points, bool is_h = true);
    QPoint getOriginCoord();
    void setOriginCoord(const QPoint&);
    int getRote();
    void setRote(const int&);
    int showScale();
    void setShowScale(const int&);
signals:
    void updateSignal();
private slots:
    void onUpdated();
private:
    QPoint m_originCoord;
    int m_rote = 0;
    int m_showScale = 1;
};

#endif // MYPAINTER_H
