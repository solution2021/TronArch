﻿

#ifndef ZCAPPVAR_H
#define ZCAPPVAR_H

#include "zacdb.h"
#include "zacadstrc.h"
#include "zAcDbCore2dDefs.h"

#pragma pack (push, 8)

enum {
    kGroupsOn     = 0x01,
    kHatchAssocOn = 0x02
};

class ZCDBCORE2D_PORT ZcDbAppSystemVariables {
public:
    inline ZcDbAppSystemVariables();
    inline ~ZcDbAppSystemVariables() {};
	Zcad::ErrorStatus setAttdia(bool value, bool bUndo = false);
    inline bool attdia() const;
	Zcad::ErrorStatus setAttreq(bool, bool bUndo = false);
    inline bool attreq() const;
	Zcad::ErrorStatus setBlipmode(bool, bool bUndo = false);
    inline bool blipmode() const;
	 Zcad::ErrorStatus setCoords(ZSoft::Int16 value, bool bUndo = false);
    inline ZSoft::Int16 coords() const;
	Zcad::ErrorStatus setStatusbar(ZSoft::Int16 value, bool bUndo = false);
	inline ZSoft::Int16 statusbar() const;
	Zcad::ErrorStatus setMenubar(bool value, bool bUndo = false);
	inline bool menubar() const;
	Zcad::ErrorStatus setAppStatusBarUseIcons(bool value, bool bUndo = false);
	inline bool appstatusbaruseicons() const;
	Zcad::ErrorStatus setDelUsedObj(ZSoft::Int16, bool bUndo = false);
    inline ZSoft::Int16 delUsedObj() const;
	Zcad::ErrorStatus setDragmode(ZSoft::Int16, bool bUndo = false);
    inline ZSoft::Int16 dragmode() const;
	Zcad::ErrorStatus setOsmode(ZSoft::Int16 value, bool bUndo = false);
    inline ZSoft::Int16 osmode() const;
	Zcad::ErrorStatus setPickstyle(ZSoft::Int16 value, bool bUndo = false);
    inline ZSoft::Int16 pickstyle() const;
	Zcad::ErrorStatus setLwdefault(ZcDb::LineWeight value, bool bUndo = false);
    inline ZcDb::LineWeight lwdefault() const;
	Zcad::ErrorStatus setHpassoc(bool value, bool bUndo = false);
    inline bool hpassoc() const;
	Zcad::ErrorStatus setCursorsize(ZSoft::Int16 value, bool bUndo = false);
	inline ZSoft::Int16 cursorsize() const; 

private:
    bool m_attdia;
    bool m_attreq;
    bool  m_blipmode;
    short m_delobj;
    short m_coords;
	short m_statusbar;
	bool  m_menubar;
	bool  m_appstatusbaruseicons;
    short m_dragmode;
    short m_osmode;
    short m_pkstyle;
    ZcDb::LineWeight  m_lwdefault;
    bool  m_hpassoc;
	short m_cursorsize; 
};


inline bool ZcDbAppSystemVariables::attdia() const
{
    return m_attdia;
}

inline bool ZcDbAppSystemVariables::attreq() const
{
    return m_attreq;
}

inline bool ZcDbAppSystemVariables::blipmode() const
{
    return m_blipmode;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::coords() const
{
    return m_coords;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::statusbar() const
{
	return m_statusbar;
}

inline bool ZcDbAppSystemVariables::menubar() const
{
	return m_menubar;
}

inline bool ZcDbAppSystemVariables::appstatusbaruseicons() const
{
	return m_appstatusbaruseicons;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::delUsedObj() const
{
    return m_delobj;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::dragmode() const
{
    return m_dragmode;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::osmode() const
{
    return m_osmode;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::pickstyle() const
{
    return m_pkstyle;
}

inline ZcDb::LineWeight ZcDbAppSystemVariables::lwdefault() const
{
    return m_lwdefault;
}

inline bool ZcDbAppSystemVariables::hpassoc() const
{
    return m_hpassoc;
}

inline ZSoft::Int16 ZcDbAppSystemVariables::cursorsize() const
{
	return m_cursorsize;
} 
 
#pragma pack (pop)
#endif 
