#ifndef LETTERRAIN_H
#define LETTERRAIN_H

#include <QChar>
#include <QVector>

class LetterRain
{
public:
	explicit LetterRain(int head_x, int head_y, int height_boundary, int pixel_size, int num_letter);
	~LetterRain();

public:
	void fall(int fall_speed);
	void paint(QPainter *painter);

private:
	void random_fill();

private:
	int m_head_x;
	int m_head_y;
	int m_height_boundary;
	int m_pixel_size;
	int m_num_letter;
	QVector<QChar> m_letter;
};

#endif // LETTERRAIN_H