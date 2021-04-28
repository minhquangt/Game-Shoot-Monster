#include"BaseObject.h"

BaseObject::BaseObject()
{
	p_object_ = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
}

BaseObject::~BaseObject()
{
	Free();
}
bool BaseObject::LoadImg(std::string path, SDL_Renderer* screen)
{
	Free();

	SDL_Texture* new_texture = NULL;
	SDL_Surface* load_suface = IMG_Load(path.c_str());
	if (load_suface != NULL)
	{
		SDL_SetColorKey(load_suface, SDL_TRUE, SDL_MapRGB(load_suface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B)); //xóa background của nhân vật game
		new_texture = SDL_CreateTextureFromSurface(screen, load_suface);
		if (new_texture != NULL)
		{
			rect_.w = load_suface->w;
			rect_.h = load_suface->h;

		}
		SDL_FreeSurface(load_suface);
	}
	p_object_ = new_texture;
	return p_object_ != NULL;
}

void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip)
{
	SDL_Rect renderquad = { rect_.x, rect_.y, rect_.w, rect_.h };
	SDL_RenderCopy(des, p_object_, clip, &renderquad);
}

void BaseObject::Free()
{
	if (p_object_ != NULL)
	{
		SDL_DestroyTexture(p_object_);
		p_object_ = NULL;
		rect_.w = 0;
		rect_.h = 0;
	}
}
