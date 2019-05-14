#ifndef TEXTTICKER_H
#define TEXTTICKER_H


#include <QLabel>
#include <QTimer>

class TextTicker : public QLabel
{
    Q_OBJECT
public:
    TextTicker(QWidget *parent = 0);
    ~TextTicker();

    void setTickerText(const QString &);
protected:
    void paintEvent(QPaintEvent *event);
    void updateIndex();//刷新
private:
    int m_charWidth;//每个字符所占的宽度（单位是像素）
    int m_curIndex;//从哪里开始显示当前字符串
    int m_length;//需要显示的字符串加了空格之后的字符串长度
    int m_maxCount;//窗体能容纳的最大字符数，即显示字符的个数
    QString m_showText;//需要显示的字符串（初始字符串--》加空格之后的字符串--》乘以2倍后的字符串）
};

#endif // TEXTTICKER_H
