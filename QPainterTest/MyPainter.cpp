#include "MyPainter.h"
#include <QPainter>
#include <QVector>
#include <QtMath>

#define GAP_PIX 40
#define SCALE_HEIGHT 5
#define TEXT_FONT_SIZE 10

MyPaniter::MyPaniter(QQuickItem* parent) : QQuickPaintedItem(parent)
{
    bool suc = true;
    suc = connect(this,&MyPaniter::updateSignal, this, &MyPaniter::onUpdated);
}

void MyPaniter::onUpdated()
{
    update();
}

void MyPaniter::calScalesPoint(qreal len, QVector<QPoint>& scale_points, bool is_h)
{
    int gap_pix = GAP_PIX;
    if(is_h){
        //m_originCoord正方向的点
        int i = 0;
        while( i*gap_pix < width()- m_originCoord.x()){
            QPoint point = QPoint(i * gap_pix,0);
            scale_points.push_back(point);
            i++;
        }
        //m_originCoord负方向的点
        i=1;
        while( 0 < m_originCoord.x() - i*gap_pix){
            QPoint point = QPoint(-i * gap_pix,0);
            scale_points.push_back(point);
            i++;
        }
    }else{
        //m_originCoord正方向的点
        int i = 0;
        while( i*gap_pix < height() - m_originCoord.y()){
            QPoint point = QPoint(0, i * gap_pix);
            scale_points.push_back(point);
            i++;
        }
        //m_originCoord负方向的点
        i=1;
        while( 0 < m_originCoord.y() - i*gap_pix){
            QPoint point = QPoint(0, -i * gap_pix);
            scale_points.push_back(point);
            i++;
        }
    }
}

void MyPaniter::drawScalesPoints(QPainter *painter, const QVector<QPoint>& scale_points, bool is_h)
{
    painter->save();
    QFont font;
    int font_size = TEXT_FONT_SIZE;
    font.setPixelSize(font_size);
    painter->setFont(font);
    for(int i =0; i < scale_points.size(); i++){
        if(is_h){
            QPoint p1 = scale_points[i];
            QPoint p2 = QPoint(p1.x(), SCALE_HEIGHT);
            painter->drawLine(p1, p2);
            //通过p1点的坐标来算数字
            int num = p1.x();

            if(num!=0){
                painter->drawText(p1.x()-font_size/3, SCALE_HEIGHT+10, QString("%1").arg(num));
            }
        }else{
            QPoint p1 = scale_points[i];
            QPoint p2 = QPoint(SCALE_HEIGHT, p1.y());
            painter->drawLine(p1,p2);
            int num = p1.y();
            if(num!=0){
                painter->drawText(SCALE_HEIGHT+2, p1.y()+font_size/3, QString("%1").arg(num));
            }
        }
    }
    painter->restore();
}

//画一个坐标系，标出刻度
void MyPaniter::drawCoordSys(QPainter *painter)
{
    int w = (int)width();
    int h = (int)height();

    painter->drawLine(0-m_originCoord.x(), 0, w-m_originCoord.x(), 0);
    painter->drawLine(0, 0-m_originCoord.y(), 0, h-m_originCoord.y());

    //painter->drawLine(0-m_originCoord.x()/cos(m_rote), 0, w/cos(m_rote)-m_originCoord.x(), 0);
    //painter->drawLine(0, 0-m_originCoord.y()/cos(m_rote), 0, h/cos(m_rote)-m_originCoord.y());

    QVector<QPoint> scale_h;//横刻度
    QVector<QPoint> scale_v;//纵刻度
    calScalesPoint(w, scale_h);
    calScalesPoint(h, scale_v,false);
    drawScalesPoints(painter, scale_h);
    drawScalesPoints(painter, scale_v, false);
}

void MyPaniter::paint(QPainter *painter)
{   
    painter->translate(m_originCoord);
    painter->drawText(10,-5, QString("(%1,%2)").arg(m_originCoord.x()).arg(m_originCoord.y()));
    painter->rotate(m_rote);

    if(m_showScale){
        drawCoordSys(painter);
    }
    painter->setPen(Qt::red);
    painter->drawRect(0,0,60,40);
}

QPoint MyPaniter::getOriginCoord()
{
    return m_originCoord;
}
void MyPaniter::setOriginCoord(const QPoint& p)
{
   m_originCoord = p;
   emit updateSignal();
}

int MyPaniter::getRote()
{
   return m_rote;
}

void MyPaniter::setRote(const int& rote)
{
    m_rote = rote;
    emit updateSignal();
}

int MyPaniter::showScale()
{
   return m_showScale;
}

void MyPaniter::setShowScale(const int& show_scale)
{
   m_showScale = show_scale;
   emit updateSignal();
}
