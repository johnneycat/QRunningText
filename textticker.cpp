#include "textticker.h"

TextTicker::TextTicker(QWidget *parent)
    : QLabel(parent)
{
    //设置背景颜色
    this->setStyleSheet("background-color:red");
    //设置字体大小
    QFont font;
    font.setPointSize(40);
    font.setBold(true);
    this->setFont(font);
    //设置字体颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::yellow);
    this->setPalette(pa);
    //给需要被显示的字符串赋初值
//    m_showText = QStringLiteral("床前明月光，疑是地上霜，举头望明月，低头思故乡。床前明月光，疑是地上霜，举头望明月，低头思故乡。");

//    //字符串初值后边加空格（当前一遍的尾巴和头需要同时显示的时候，加上少量空格，使显示更好看）
//    m_showText += "          ";
//    //获取添加空格后的需要显示的字符串的长度
//    m_length = m_showText.size();
//    //解决当前一遍的尾巴和头需要同时显示
//    m_showText += m_showText;//需要打印的字符串 * 2
//    //当前角码
//    m_curIndex = 0;
//    //每个字符的宽度
//    m_charWidth = fontMetrics().width("a");
//    QTimer *timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, &TextTicker::updateIndex);
//    timer->start(200);
}
TextTicker::~TextTicker()
{
}

void TextTicker::paintEvent(QPaintEvent *event)
{
    __super::paintEvent(event);
    this->setText(m_showText.mid(m_curIndex, m_maxCount));
}
void TextTicker::updateIndex()
{
    m_maxCount = width() / m_charWidth;
    m_curIndex++;
    if (m_curIndex >= m_length)
        m_curIndex = 0;
    update();
}

void TextTicker::setTickerText(const QString & text)
{
    m_showText = text;
    m_length = m_showText.size();
    m_maxCount = width() / m_charWidth;
    if(m_length > m_maxCount)
    {
        m_showText += "          ";
        //获取添加空格后的需要显示的字符串的长度
        m_length = m_showText.size();
        //解决当前一遍的尾巴和头需要同时显示
        m_showText += m_showText;//需要打印的字符串 * 2
        //当前角码
        m_curIndex = 0;
        //每个字符的宽度
        m_charWidth = fontMetrics().width("a");
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &TextTicker::updateIndex);
        timer->start(200);
    }
}


