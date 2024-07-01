
#pragma once
#pragma pack (push, 8)

#ifndef ZCSYNERGY_PORT
#define ZCSYNERGY_PORT _declspec(dllexport)
#endif




class ZcDbImpViewBorder;

class ZCSYNERGY_PORT ZcDbViewBorder : public ZcDbEntity
{
    friend class ZcDbAssocViewRepActionBody;
    friend class ZcDbImpViewBorder;
    friend class ZcDbImpViewSymbol;
public:
    ZCRX_DECLARE_MEMBERS(ZcDbViewBorder);

    ZcDbViewBorder();

    virtual ~ZcDbViewBorder();

    enum ViewStyleType 
    {
        kFromBase               = 0,
        kWireframeVisibleEdges  = 1,
        kWireframeHiddenEdges   = 2,
        kShadedVisibleEdges     = 3,
        kShadedHiddenEdges      = 4
    };

    enum SourceType
    {
        kSourceNotDefined   = 0,
        kInventorSource     = 1,
        kFusionSource       = 2,
        kModelSpaceSource   = 3
    };

    ZcGePoint3d                 insertionPoint() const;
    double                      height() const;
    double                      width() const;
    ZcDbViewBorder::SourceType  sourceType() const;
    ZcString                    inventorFileReference() const;
    bool                        isFirstAngleProjection() const;
    double                      rotationAngle() const;
    ZcDbViewBorder::ViewStyleType viewStyleType() const;
    double                      scale() const;
    ZSoft::UInt32               shadedDPI() const;

    ZcDbObjectId                viewportId() const;

    virtual ZSoft::Boolean      subWorldDraw(ZcGiWorldDraw* pWd);

    virtual Zcad::ErrorStatus   subErase(ZSoft::Boolean erasing);
    virtual Zcad::ErrorStatus   subDeepClone(ZcDbObject* pOwnerObject, ZcDbObject*& pClonedObject, 
                                    ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary = true) const;
    virtual Zcad::ErrorStatus   subWblockClone(ZcRxObject* pOwnerObject, ZcDbObject*& pClonedObject, 
                                    ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary = true) const;

    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus   audit(ZcDbAuditInfo* pAuditInfo);

    virtual Zcad::ErrorStatus   subGetStretchPoints(ZcGePoint3dArray& stretchPoints) const;
    virtual Zcad::ErrorStatus   subMoveStretchPointsAt(const ZcDbIntArray & indices, 
                                                       const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus   subGetGripPoints(ZcDbGripDataPtrArray& grips, 
                                                 const double curViewUnitSize, 
                                                 const int gripSize, 
                                                 const ZcGeVector3d& curViewDir, 
                                                 const int bitflags) const;
    virtual Zcad::ErrorStatus   subGetGripPoints(ZcGePoint3dArray& gripPoints, 
                                                 ZcDbIntArray & osnapModes, 
                                                 ZcDbIntArray & geomIds) const;
    virtual Zcad::ErrorStatus   subMoveGripPointsAt(const ZcDbVoidPtrArray& gripAppData,
                                                 const ZcGeVector3d& offset, 
                                                 const int bitflags);
    virtual Zcad::ErrorStatus   subMoveGripPointsAt(const ZcDbIntArray & indices, 
                                                    const ZcGeVector3d& offset);
    virtual void                subGripStatus(const ZcDb::GripStat status);

    virtual Zcad::ErrorStatus   subGetOsnapPoints(ZcDb::OsnapMode osnapMode, 
                                                  ZSoft::GsMarker gsSelectionMark, 
                                                  const ZcGePoint3d& pickPoint, 
                                                  const ZcGePoint3d& lastPoint, 
                                                  const ZcGeMatrix3d& viewXform, 
                                                  ZcGePoint3dArray& snapPoints, 
                                                  ZcDbIntArray & geomIds) const;

    virtual Zcad::ErrorStatus   subGetOsnapPoints(ZcDb::OsnapMode osnapMode, 
                                                  ZSoft::GsMarker gsSelectionMark, 
                                                  const ZcGePoint3d& pickPoint, 
                                                  const ZcGePoint3d& lastPoint, 
                                                  const ZcGeMatrix3d& viewXform, 
                                                  ZcGePoint3dArray& snapPoints, 
                                                  ZcDbIntArray & geomIds, 
                                                  const ZcGeMatrix3d& insertionMat) const;

    virtual Zcad::ErrorStatus   subIntersectWith(const ZcDbEntity* pEnt, 
                                                 ZcDb::Intersect intType, 
                                                 const ZcGePlane& projPlane, 
                                                 ZcGePoint3dArray& points, 
                                                 ZSoft::GsMarker thisGsMarker = 0, 
                                                 ZSoft::GsMarker otherGsMarker = 0) const;

    virtual Zcad::ErrorStatus   subIntersectWith(const ZcDbEntity* pEnt, 
                                                 ZcDb::Intersect intType, 
                                                 ZcGePoint3dArray& points, 
                                                 ZSoft::GsMarker thisGsMarker = 0, 
                                                 ZSoft::GsMarker otherGsMarker = 0) const;

    virtual Zcad::ErrorStatus   subTransformBy(const ZcGeMatrix3d& xform);

    virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const;

    virtual void                subList() const;

    virtual Zcad::ErrorStatus   subHighlight(const ZcDbFullSubentPath& subId = kNullSubent, 
                                             const ZSoft::Boolean highlightAll = false) const;

    virtual Zcad::ErrorStatus   subUnhighlight(const ZcDbFullSubentPath& subId = kNullSubent, 
                                               const ZSoft::Boolean highlightAll = false) const;

    virtual  Zcad::ErrorStatus  subGetSubentPathsAtGsMarker(ZcDb::SubentType       type,
                                                            ZSoft::GsMarker        gsMark, 
                                                            const ZcGePoint3d&     pickPoint,
                                                            const ZcGeMatrix3d&    viewXform, 
                                                            int&                   numPaths,
                                                            ZcDbFullSubentPath*&   subentPaths, 
                                                            int                    numInserts = 0,
                                                            ZcDbObjectId*          entAndInsertStack
                                                                                    = NULL) const;

    virtual  Zcad::ErrorStatus  subGetGsMarkersAtSubentPath(const ZcDbFullSubentPath& subPath, 
                                                            ZcArray<ZSoft::GsMarker>& gsMarkers) const;

    virtual  Zcad::ErrorStatus  subGetSubentClassId(const ZcDbFullSubentPath& path, CLSID* clsId) const;

    virtual void                saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st);

    virtual Zcad::ErrorStatus   setLayer(const ZTCHAR* newVal,
                                         ZSoft::Boolean doSubents = true,
                                         bool allowHiddenLayer = false);
    virtual Zcad::ErrorStatus   setLayer(ZcDbObjectId newVal,
                                         ZSoft::Boolean doSubents = true,
                                         bool allowHiddenLayer = false);
    
    Zcad::ErrorStatus           setViewportId(const ZcDbObjectId& viewportId);
    ZcGePoint2d                 centerPoint(bool exludeSketchEnts = true) const;
    ZcGePoint3d                 centerPoint3d(bool exludeSketchEnts = true) const;
    Zcad::ErrorStatus           getSize(ZcGePoint3d& minPt,
                                        ZcGePoint3d& maxPt) const;
    Zcad::ErrorStatus           setSize(const ZcGePoint3d& minPt,
                                        const ZcGePoint3d& maxPt);
    void                        setScale(double newScale);
    Zcad::ErrorStatus           recalculateBorder();

    void                        setTransientEnts(const ZcArray<ZcDbEntity*>& traientEnts);
    void                        setDisableUnHighlight(bool bIsDisable);
    bool                        hitTest(const ZcGePoint3d& inputPt) const;

    
    Zcad::ErrorStatus getSubentColor(const ZcDbSubentId& subentId, ZcCmColor& color) const;
    Zcad::ErrorStatus setSubentColor(const ZcDbSubentId& subentId, const ZcCmColor& color);

    Zcad::ErrorStatus getSubentLayerId(const ZcDbSubentId& subentId, ZcDbObjectId& layerId) const;
    Zcad::ErrorStatus setSubentLayer(const ZcDbSubentId& subentId, ZcDbObjectId newVal);

    Zcad::ErrorStatus getSubentLinetypeId(const ZcDbSubentId& subentId, ZcDbObjectId& linetypeId) const;
    Zcad::ErrorStatus setSubentLinetype(const ZcDbSubentId& subentId, ZcDbObjectId newVal);

    Zcad::ErrorStatus getSubentLinetypeScale(const ZcDbSubentId& subentId, double& linetypeScale) const;
    Zcad::ErrorStatus setSubentLinetypeScale(const ZcDbSubentId& subentId, double newVal);

    ZTCHAR*            getSubentPlotStyleName(const ZcDbSubentId& subentId) const;
    Zcad::ErrorStatus setSubentPlotStyleName(const ZcDbSubentId& subentId, const ZTCHAR* newName);

    Zcad::ErrorStatus getSubentLineWeight(const ZcDbSubentId& subentId, ZcDb::LineWeight& lineweight) const;
    Zcad::ErrorStatus setSubentLineWeight(const ZcDbSubentId& subentId, ZcDb::LineWeight newVal);

    Zcad::ErrorStatus getSubentVisibility(const ZcDbSubentId& subentId, ZcDb::Visibility& visVal) const;
    Zcad::ErrorStatus setSubentVisibility(const ZcDbSubentId& subentId, ZcDb::Visibility newVal);

    Zcad::ErrorStatus subentIdToNestedEnts (const ZcDbSubentId& subentId, ZcDbFullSubentPathArray &nestedEnts) const;

private:
    ZcGeMatrix3d            transientXform() const;

private:
    ZcDbImpViewBorder*          mpZcDbImpViewBorder;

    static  double              sViewBoderOffset;
};


#pragma pack (pop)
