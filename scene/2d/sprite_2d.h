/**************************************************************************/
/*  sprite_2d.h                                                           */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef SPRITE_2D_H
#define SPRITE_2D_H

#include "scene/2d/node_2d.h"
#include "scene/resources/texture.h"

// Sprite2D 类继承自 Node2D，表示一个2D精灵
class Sprite2D : public Node2D {
	GDCLASS(Sprite2D, Node2D);

	// 精灵的纹理
	Ref<Texture2D> texture;
	// 镜面反射颜色
	Color specular_color;
	// 光泽度
	real_t shininess = 0.0;

	// 是否居中
	bool centered = true;
	// 偏移量
	Point2 offset;

	// 水平翻转
	bool hflip = false;
	// 垂直翻转
	bool vflip = false;
	// 翻转效果
	bool flip_effect = false;
	// 是否启用区域
	bool region_enabled = false;
	// 区域矩形
	Rect2 region_rect;
	// 是否启用区域过滤剪裁
	bool region_filter_clip_enabled = false;

	// 当前帧
	int frame = 0;

	// 垂直帧数
	int vframes = 1;
	// 水平帧数
	int hframes = 1;

	// 获取源矩形和目标矩形
	void _get_rects(Rect2 &r_src_rect, Rect2 &r_dst_rect, bool &r_filter_clip_enabled) const;

	// 纹理改变时的回调
	void _texture_changed();

protected:
	// 通知处理
	void _notification(int p_what);

	// 绑定方法
	static void _bind_methods();

	// 验证属性
	void _validate_property(PropertyInfo &p_property) const;

public:
#ifdef TOOLS_ENABLED
	// 编辑器获取状态
	virtual Dictionary _edit_get_state() const override;
	// 编辑器设置状态
	virtual void _edit_set_state(const Dictionary &p_state) override;

	// 编辑器设置枢轴
	virtual void _edit_set_pivot(const Point2 &p_pivot) override;
	// 编辑器获取枢轴
	virtual Point2 _edit_get_pivot() const override;
	// 编辑器是否使用枢轴
	virtual bool _edit_use_pivot() const override;
#endif // TOOLS_ENABLED

#ifdef DEBUG_ENABLED
	// 编辑器点击时是否选中
	virtual bool _edit_is_selected_on_click(const Point2 &p_point, double p_tolerance) const override;

	// 编辑器获取矩形
	virtual Rect2 _edit_get_rect() const override;
	// 编辑器是否使用矩形
	virtual bool _edit_use_rect() const override;
#endif // DEBUG_ENABLED

	// 判断像素是否不透明
	bool is_pixel_opaque(const Point2 &p_point) const;

	// 设置纹理
	void set_texture(const Ref<Texture2D> &p_texture);
	// 获取纹理
	Ref<Texture2D> get_texture() const;

	// 设置是否居中
	void set_centered(bool p_center);
	// 获取是否居中
	bool is_centered() const;

	// 设置偏移量
	void set_offset(const Point2 &p_offset);
	// 获取偏移量
	Point2 get_offset() const;

	// 设置水平翻转
	void set_flip_h(bool p_flip);
	// 获取是否水平翻转
	bool is_flipped_h() const;

	// 设置垂直翻转
	void set_flip_v(bool p_flip);
	// 获取是否垂直翻转
	bool is_flipped_v() const;
	
	// 设置翻转效果
	void set_flip_effect(bool p_enable);
	// 获取翻转效果
	bool is_flip_effect() const;
	
	// 设置是否启用区域
	void set_region_enabled(bool p_enabled);
	// 获取是否启用区域
	bool is_region_enabled() const;

	// 设置是否启用区域过滤剪裁
	void set_region_filter_clip_enabled(bool p_enabled);
	// 获取是否启用区域过滤剪裁
	bool is_region_filter_clip_enabled() const;

	// 设置区域矩形
	void set_region_rect(const Rect2 &p_region_rect);
	// 获取区域矩形
	Rect2 get_region_rect() const;

	// 设置当前帧
	void set_frame(int p_frame);
	// 获取当前帧
	int get_frame() const;

	// 设置帧坐标
	void set_frame_coords(const Vector2i &p_coord);
	// 获取帧坐标
	Vector2i get_frame_coords() const;

	// 设置垂直帧数
	void set_vframes(int p_amount);
	// 获取垂直帧数
	int get_vframes() const;

	// 设置水平帧数
	void set_hframes(int p_amount);
	// 获取水平帧数
	int get_hframes() const;

	// 获取矩形
	Rect2 get_rect() const;
	// 获取可锚定的矩形
	virtual Rect2 get_anchorable_rect() const override;

	// 构造函数
	Sprite2D();
	// 析构函数
	~Sprite2D();
};

#endif // SPRITE_2D_H
