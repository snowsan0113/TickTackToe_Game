#pragma once

enum DrawType {
	LEFT,
	CENTER,
	RIGHT
};


void drawText(DrawType type, int x, int y, int size, const char* text, unsigned int text_color, unsigned int edge_color);