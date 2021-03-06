#pragma once

#include "cobj\Obj.h"

#include "cobj\Cylinder.h"
#include "cobj\Cube.h"
#include "cobj\Prism.h"
#include "cobj\Sphere.h"
#include "cobj\ObjFile.h"
#include "cobj\helicopter.h"

class CDocObj
{
public:
	CDocObj();
	CDocObj(CString name, OBJ_TYPE type);
	CDocObj(CString name, CString file_name);
	~CDocObj();

	CString m_name;
	CObj* m_obj;
	OBJ_TYPE m_type;
	bool m_whether_texture;
	bool m_texture_loaded;

	CString m_texture_file_name;
	GLuint m_texture;
	BYTE* m_bitmapData;
	void draw_property(CMFCPropertyGridCtrl* PropList);
	void change_value(CMFCPropertyGridProperty* pProp);
	void draw();
	bool is_collision(float x, float y, float z)
	{
		return m_obj->is_collision(x, y, z);
	}

	void draw_property_obj(CMFCPropertyGridCtrl* PropList);
	void draw_property_cube(CMFCPropertyGridCtrl* PropList);
	void draw_property_cylinder(CMFCPropertyGridCtrl* PropList);
	void draw_property_prism(CMFCPropertyGridCtrl* PropList);
	void draw_property_sphere(CMFCPropertyGridCtrl* PropList);
	void draw_property_objfile(CMFCPropertyGridCtrl* PropList);

	void texload(const char *filename);
	unsigned char *LoadBitmapFile(const char *filename, BITMAPINFOHEADER *bitmapInfoHeader);

	void exportobj(CString filename);
};

