#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include"commonfunc.h"
class BaseObject
{
public:
	BaseObject();
	~BaseObject();

	void SetRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }
	SDL_Rect GetRect() const { return rect_; }
	SDL_Texture* GetObject() const { return p_object_; }

	virtual bool LoadImg(std::string path, SDL_Renderer* screen); //Load ảnh lên đối tượng p_object_, sử dụng p_object_ để thêm nó vào màn hình
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
	void Free();
protected:
	SDL_Texture* p_object_; // biến lưu trữ hình ảnh
	SDL_Rect rect_; // lưu kích thước của ảnh
};
#endif;


