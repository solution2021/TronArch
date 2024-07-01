

#ifndef   _ZCAPLMGR_H
#define   _ZCAPLMGR_H

#include "zAcDbLMgr.h"
#pragma pack (push, 8)

class ZcDbObjectId;
class ZcGePoint2d;
class ZcGePoint3d;

template <class T> class ZcArrayMemCopyReallocator;
template <class T, class R > class ZcArray;
typedef ZcArray<ZcGePoint2d> ZcGePoint2dArray;

class ZcApLayoutManager : public ZcDbLayoutManager 
{
  public:

    virtual int               
    pageSetup                 (ZcDbObjectId layoutBTRId = ZcDbObjectId::kNull, 
                               void* pParent = nullptr,
                               ZSoft::Boolean isPageSetupDlg = TRUE) = 0;

    virtual void              
    updateCurrentPaper        (ZSoft::Boolean zoomToPaper = FALSE  ) = 0;

    virtual void              
    updateLayoutTabs          () = 0;

    virtual Zcad::ErrorStatus  getActiveTab             (ZcString &sName) = 0;

	virtual const ZTCHAR *
		findActiveTab             () final;
                              
    virtual ZSoft::Boolean    
    showTabs                  () = 0;

    virtual void              
    setShowTabs               (ZSoft::Boolean showTabs           ) = 0;

    virtual ZSoft::Boolean    
    showPageSetup             () = 0;

    virtual void              
    setShowPageSetup          (ZSoft::Boolean showPageSetupDlg   ) = 0;

    virtual ZSoft::Boolean    
    createViewports           () = 0;

    virtual void              
    setCreateViewports        (ZSoft::Boolean createViewports    ) = 0;

    virtual ZSoft::Boolean    
    showPaperBackground       () = 0;

    virtual void              
    setShowPaperBackground    (ZSoft::Boolean showPaperBackground) = 0;

    virtual ZSoft::Boolean    
    showPaperMargins          () = 0; 

    virtual void              
    setShowPaperMargins       (ZSoft::Boolean showPaperMargins   ) = 0;

    virtual ZSoft::Boolean    
    showPrintBorder           () = 0;
	
    virtual void              
    setShowPrintBorder        (ZSoft::Boolean showPrintBorder    ) = 0;

    virtual Zcad::ErrorStatus  generateNextNewLayoutName(ZcString &sName,
                                                         ZcDbDatabase* useDb = nullptr) = 0;
	virtual ZTCHAR *
    getNextNewLayoutName      (ZcDbDatabase* useDb = nullptr) final;

    virtual void 
    setDefaultPlotConfig      (ZcDbObjectId layoutBTRId) = 0;

    virtual Zcad::ErrorStatus   
    getClipBoundaryElaboration(ZcDbObjectId clipId,
                               ZcGePoint2dArray *&clipBoundary) = 0;

    virtual Zcad::ErrorStatus 
    pointInViewports          (const ZcGePoint3d &pickPt, 
                               ZcDbObjectIdArray &viewports) = 0;

	virtual void setCaptureOnLayoutSwitch(bool bCaptureOnLayout   ) = 0;

    virtual Zcad::ErrorStatus
        createLayoutFromTemplate(const ZTCHAR *newLayoutName, ZcDbObjectId& newLayoutId,
            const ZTCHAR *templatePath, const ZTCHAR *layoutName, ZcDbDatabase* pDb = NULL) = 0;

};
#pragma pack (pop)

inline const ZTCHAR * ZcApLayoutManager::findActiveTab()
{
    static ZcString sCachedName;
    this->getActiveTab(sCachedName);
    return sCachedName.constPtr();
}

inline ZTCHAR * ZcApLayoutManager::getNextNewLayoutName(ZcDbDatabase* useDb)
{
    ZcString sName;
    return ::zcutZcStringToZTChar(sName, this->generateNextNewLayoutName(sName, useDb));
}

#endif 

