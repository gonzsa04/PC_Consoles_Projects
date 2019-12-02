#pragma once
#include <stdint.h>
#include <Utils/Resources.h>

class RendererThread;

class Sprite {
public:
	Sprite();
	~Sprite();

	void setImage(Resources::ImageId id);

	int getWidth();
	int getHeight();

	void draw(int x, int y, RendererThread* renderThread);
	void draw(int x, int y, int left, int top, int right, int bottom, RendererThread * renderThread);
	void draw(int x, int y, char rows, char cols, char frame, RendererThread * renderThread);

private:
	uint32_t* _image;
	int  _width, _height;

	void sendDrawCommand(int x, int y, int left, int top, int right, int bottom, RendererThread * renderThread);
};