﻿
#ifndef __ZDBWIPE_H__
#define __ZDBWIPE_H__

#ifdef _DBWIPEOBJ_
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP
#endif
#include "zadesk.h"
#ifdef _ZSOFT_WINDOWS_
 #include "windows.h"
#endif
#include "zimgdef.h"
#include "zimgent.h"

namespace Ztil
{
    class Image;
};

#define WIPEOUTOBJSERVICE	ZCRX_T("WipeOut")

#pragma warning(push)
#pragma warning( disable : 4275 )

class DLLIMPEXP ZcDbWipeout : public ZcDbRasterImage
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbWipeout);

                                ZcDbWipeout();

    virtual ZcRxObject*         clone() const ZSOFT_OVERRIDE;
    virtual ZcGeVector2d        imageSize(ZSoft::Boolean bGetCachedValue = ZSoft::kFalse) const ZSOFT_OVERRIDE;
    ZcGiSentScanLines*          getScanLines(const ZcGiRequestScanLines& req) const ZSOFT_OVERRIDE;
	ZSoft::Boolean				isClipped() const;
	virtual void				setDisplayOpt(
                                    ImageDisplayOpt option,
                                    ZSoft::Boolean bValue
                                ) ZSOFT_OVERRIDE;
	virtual ZSoft::Boolean		isSetDisplayOpt(ImageDisplayOpt option) const ZSOFT_OVERRIDE;

	virtual Zcad::ErrorStatus	setBrightness( ZSoft::Int8 value ) ZSOFT_OVERRIDE;
	virtual ZSoft::Int8			brightness() const ZSOFT_OVERRIDE;

	virtual Zcad::ErrorStatus	setContrast( ZSoft::Int8 value ) ZSOFT_OVERRIDE;
	virtual ZSoft::Int8			contrast() const ZSOFT_OVERRIDE;

	virtual Zcad::ErrorStatus	setFade( ZSoft::Int8 value ) ZSOFT_OVERRIDE;
	virtual ZSoft::Int8			fade() const ZSOFT_OVERRIDE;

    virtual ZcGeVector2d        scale() const ZSOFT_OVERRIDE;
    Zcad::ErrorStatus           append(ZcDbObjectId& id);
    static Zcad::ErrorStatus    createImageDefinition();
    static Zcad::ErrorStatus    fitPointsToImage(
                                    ZcGePoint2dArray& pointArray,
                                    ZcGePoint2d& minPoint,
                                    double& scale,
                                    ZSoft::Boolean bFlipY = ZSoft::kFalse);
    ZSoft::Boolean        frame() const;
protected:
	
    virtual ZSoft::Boolean      subWorldDraw(ZcGiWorldDraw* mode) ZSOFT_OVERRIDE;
    virtual void                subViewportDraw(ZcGiViewportDraw* mode) ZSOFT_OVERRIDE;

    virtual void                subList() const ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus   subMoveGripPointsAt(
                                   const ZcDbVoidPtrArray& gripAppData,
                                   const ZcGeVector3d& offset, 
                                   const int bitflags) ZSOFT_OVERRIDE;
    virtual Zcad::ErrorStatus   subMoveGripPointsAt(
                                   const ZcDbIntArray& indices,
                                   const ZcGeVector3d&     offset) ZSOFT_OVERRIDE;
    virtual Zcad::ErrorStatus   subTransformBy(
                                    const ZcGeMatrix3d& xform) ZSOFT_OVERRIDE;
    virtual Zcad::ErrorStatus   subGetTransformedCopy(
                                    const ZcGeMatrix3d& xform,
                                    ZcDbEntity*& ent
                                ) const ZSOFT_OVERRIDE;
    virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const ZSOFT_OVERRIDE;
    virtual ZSoft::UInt32       subSetAttributes (ZcGiDrawableTraits * traits) ZSOFT_OVERRIDE;
	
private:
    ZSoft::Boolean              isHighlighted() const;

    void                        getPlane(ZcGeBoundedPlane& boundedPlane) const;
    ZcGeMatrix2d                fastMatrixInvert(const ZcGeMatrix2d& m) const;
    void                        drawFrame(
                                    ZcGiViewportDraw* mode,
                                    const ZcGePoint3dArray& verts) const;
    Zcad::ErrorStatus           setDcToScreen(
                                    const ZcGePoint2d& lowerLeft,
                                    const ZcGePoint2d& upperRight,
                                    int width,
                                    int height,
                                    ZcGeMatrix2d& dcToScreen) const;
    void                        setFrameExtents(
                                    ZcGiWorldDraw* mode,
                                    const ZcGePoint3dArray& verts) const;
	
    bool                        drawFilledPloygon(  ZcGiViewportDraw* mode, 
                                                    const ZcGePoint3dArray& verts) const;
    bool                        IsSelfIntersecting( const ZcGePoint3dArray& verts) const;

    ZSoft::Boolean              isFrameVisible(ZSoft::Boolean bPlotting = ZSoft::kFalse) const;
	
public:
    static long                 mImageData;

private:
    ZSoft::Boolean              mHighlight;

    void *operator new[](size_t nSize) throw() { return 0;}
    void operator delete[](void *p) {};
    void *operator new[](size_t nSize, const char *file, int line) throw() { return 0;}

};

#pragma warning(pop)
#endif 
