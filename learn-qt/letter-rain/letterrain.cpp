#include <QPainter>
#include <QPointF>

#include "letterrain.h"

LetterRain::LetterRain(int head_x, int head_y, int height_boundary, int pixel_size, int num_letter)
{
	m_head_x = head_x;
	m_head_y = head_y;
	m_height_boundary = height_boundary;
	m_pixel_size = pixel_size;
	m_num_letter = num_letter;

	random_fill();
}

void LetterRain::random_fill()
{
	m_letter.resize(m_num_letter);

	for (int i = 0; i < m_num_letter; ++i)
	{
		m_letter[i] = QChar('0' + qrand() % 2);
	}
}

void LetterRain::fall(int fall_speed)
{
	m_head_y += fall_speed;

	if (m_head_y >= m_height_boundary)
	{
		m_head_y = 0;
		random_fill();
	}
}

void LetterRain::paint(QPainter *painter)
{
	QFont font;
	// 设置字体的点数大小
	// font.setPointSize(m_pixel_size);
	// 设置字体的像素大小
	font.setPixelSize(m_pixel_size);
	painter->setFont(font);

	for (int i = 0; i < m_letter.size(); ++i)
	{
		int next_y = m_head_y + i * m_pixel_size;

		if (next_y < m_height_boundary)
		{
			// 设置画笔颜色
			painter->setPen(QColor(0, 30 * (i + 1), 0));
			// 绘制区域
			painter->drawText(m_head_x, next_y, QString(m_letter[i]));
		}
	}
}

LetterRain::~LetterRain()
{
}
