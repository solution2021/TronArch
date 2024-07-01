﻿
#pragma once
#pragma pack (push, 8)
#pragma warning (disable: 4311 4312)

#ifdef _MANAGED
#pragma warning( disable : 4561 )
#endif

#ifdef _FULLDEBUG_
#define ZC_FULL_DEBUG 1
#pragma message ("Warning! _FULLDEBUG_ is deprecated.")
#endif
#pragma comment (lib ,"ZYXRx.lib")
#pragma comment (lib ,"ZYXDatabaseMgd.lib")
#pragma comment (lib ,"ZYXDatabase.lib")
#pragma comment (lib ,"ZYXGeometry.lib")

#ifdef _BREP_SUPPORT_
	#pragma comment (lib ,"ZwGeometry.lib")
	#pragma comment (lib ,"ZwBrep.lib")
#endif


#ifdef _HLR_SUPPORT_
	#pragma comment (lib ,"ZwHlr.lib")
#endif

#ifdef _AMODELER_SUPPORT_
	#pragma comment (lib ,"ZwAECModeler.lib")
#endif

#pragma comment (lib ,"ZYXDatabaseMgd.lib")

#include "zacmem.h"
#include "zadesk.h"
#include "zadeskabb.h"
#include "zacadstrc.h"
#include "zrxdefs.h"
#include "zrxnames.h"
#include "zrxboiler.h"
#include "zrxclass.h"
#include "zAcDbClassIter.h"
#include "zrxdict.h"
#include "zrxobject.h"
#include "zrxsrvice.h"
#include "zrxkernel.h"
#include "zrxdlinkr.h"
#include "zrxregsvc.h"
#include "zrxevent.h"
#include "zrxiter.h"
#include "zrxditer.h"
#include "zappinfo.h"
#include "zrxprotevnt.h"

#include "PAL/api/zcodepgid.h"
#include "zAcHeapOpers.h"
#include "zAcString.h"
#include "zAdAChar.h"
#include "zacly.h"

#include "zacarray.h"
#include "zdbhandle.h"
#include "zdbid.h"
#include "zdbidar.h"
#include "zdbcolor.h"
#include "zdbptrar.h"
#include "zdrawable.h"
#include "zdbsecurity.h"
#include "zdbboiler.h"
#include "zacdb.h"
#include "zacdbabb.h"
#include "zdbAlignment.h"
#include "zdbfiler.h"
#include "zdbintar.h"
#include "zdbsubeid.h"
#include "zdbaudita.h"
#include "zdbmain.h"
#include "zdbdict.h"
#include "zdbdate.h"
#include "zdbsymtb.h"
#include "zdbsymutl.h"
#include "zdbdictdflt.h"
#include "zdbDictUtil.h"
#include "zdbcurve.h"
#include "zdbmtext.h"
#include "zdbdim.h"
#include "zdbdimdata.h"
#include "zdbents.h"
#include "zdbeval.h"
#include "zAcField.h"
#include "zDbField.h"
#include "zdbtable.h"
#include "zdbTablestyle.h"
#include "zdbdynblk.h"
#include "zdbproxy.h"
#include "zdbfcf.h"
#include "zdbapserv.h"
#include "zdbgroup.h"
#include "zdbhatch.h"
#include "zdblead.h"
#include "zdbelipse.h"
#include "zdbspline.h"
#include "zdbray.h"
#include "zdbsol3d.h"
#include "zdbregion.h"
#include "zdbacis.h"
#include "zdbbody.h"
#include "zdbframe.h"
#include "zdbole.h"
#include "zimgdef.h"
#include "zimgvars.h"
#include "zdbimage.h"
#include "zimgent.h"
#include "zdblstate.h"
#include "zdbmstyle.h"
#include "zdbmline.h"
#include "zdbxline.h"
#include "zdbxrecrd.h"
#include "zachapi.h"
#include "zdbDataTable.h"
#include "zdbfilter.h"
#ifndef _MANAGED
#include "zdbgrip.h"
#endif
#include "zdbappgrip.h"
#include "zdbidmap.h"
#include "zdbindex.h"
#include "zdblaymgrrctr.h"
#include "zdblayout.h"
#include "zdbmaterial.h"
#include "zdbpl.h"
#include "zdbtrans.h"
#include "zsorttab.h"
#include "zxreflock.h"

#include "zacgiutil.h"
#include "zdbcfilrs.h"
#include "zdblyfilt.h"
#include "zdblyindx.h"
#include "zdbspfilt.h"
#include "zdbspindx.h"
#include "zdbplhldr.h"
#include "zdbxutil.h"
#include "zidgraph.h"
#include "zsumminfo.h"
#include "ztextengine.h"
#include "zgraph.h"
#include "zxgraph.h"
#include "zdbPlotSettings.h"
#include "zdbplotsetval.h"
#include "zAcDbLMgr.h"
#include "zacappvar.h"

#include "zacgi.h"
#include "zAcGiLineAttributes.h"
#include "zAcGiLineAttrUtils.h"
#include "zacgimaterial.h"
#include "zAcGiStyleAttributes.h"
#include "zlinetypeengine.h"

#include "zacutil.h"
#include "zacestext.h"
#include "zadsdef.h"
#include "zacdbads.h"
#include "zacutads.h"
#include "zads.h"
#include "zadscodes.h"
#include "zadsmigr.h"
#include "zmigrtion.h"

#include "zdbobjptr.h"

#include "zgeassign.h"
#include "zgeblok2d.h"
#include "zgeblok3d.h"
#include "zgeell2d.h"
#include "zgeell3d.h"
#include "zgecone.h"
#include "zgecylndr.h"
#include "zgesphere.h"
#include "zgetorus.h"
#include "zgeray2d.h"
#include "zgeray3d.h"
#include "zgessint.h"
#include "zgedwgio.h"
#include "zgedxfio.h"
#include "zgefiler.h"
#include "zgecspl2d.h"
#include "zgecspl3d.h"
#include "zgepos2d.h"
#include "zgepos3d.h"
#include "zgeoffc2d.h"
#include "zgeoffc3d.h"
#include "zgeoffsf.h"
#include "zgenurb2d.h"
#include "zgenurb3d.h"
#include "zgenurbsf.h"
#include "zgecsint.h"
#include "zgeextc2d.h"
#include "zgeextc3d.h"
#include "zgeextsf.h"
#include "zgecomp2d.h"
#include "zgecomp3d.h"
#include "zgecint2d.h"
#include "zgecint3d.h"
#include "zgescl2d.h"
#include "zgescl3d.h"
#include "zgeclip2d.h"
#include "zgexbndsf.h"
#include "zgecbndry.h"
#include "zgeapln3d.h"
#include "zgearc2d.h"
#include "zgearc3d.h"
#include "zgebndpln.h"
#include "zgecurv2d.h"
#include "zgecurv3d.h"
#include "zgedblar.h"
#include "zgedll.h"
#include "zgeent2d.h"
#include "zgeent3d.h"
#include "zgefileio.h"
#include "zgegbl.h"
#include "zgegblabb.h"
#include "zgegblge.h"
#include "zgegblnew.h"
#include "zgeintarr.h"
#include "zgeintrvl.h"
#include "zgekvec.h"
#include "zgelent2d.h"
#include "zgelent3d.h"
#include "zgelibver.h"
#include "zgeline2d.h"
#include "zgeline3d.h"
#include "zgelnsg2d.h"
#include "zgelnsg3d.h"
#include "zgemat2d.h"
#include "zgemat3d.h"
#include "zgepent2d.h"
#include "zgepent3d.h"
#include "zgeplanar.h"
#include "zgeplane.h"
#include "zgeplin2d.h"
#include "zgeplin3d.h"
#include "zgepnt2d.h"
#include "zgepnt3d.h"
#include "zgeponc2d.h"
#include "zgeponc3d.h"
#include "zgeponsrf.h"
#include "zgept2dar.h"
#include "zgept3dar.h"
#include "zgesent2d.h"
#include "zgesent3d.h"
#include "zgesurf.h"
#include "zgetol.h"
#include "zgevc2dar.h"
#include "zgevc3dar.h"
#include "zgevec2d.h"
#include "zgevec3d.h"
#include "zgevptar.h"

#ifdef _MANAGED
#include <vcclr.h>
#include "zmgdinterop.h"
#endif

#ifdef __ATLCOM_H__
#ifndef _ACRXAPP
#include "zaxdb.h"		
#else
#include "zacadi.h"		
#endif
#include "zoleaprot.h"
#include "zcategory.h"
#include "zaxobjref.h"
#include "zaxboiler.h"
#include "zacpi.h"		
#include "zopmdialog.h"
#include "zopmimp.h"
#include "zopmdrvr.h"
#include "zopmext.h"
#include "zaxtempl.h"
#include "zaxpnt2d.h"
#include "zaxpnt3d.h"
#include "zaxmat3d.h"
#include "zaxlock.h"
#include "zdynprops.h"
#include "zacpexctl.h"	
#include "zAcPp.h"		
#endif

#include "zacut.h"
#include "zacutmem.h"
#include "zacutmigr.h"

#include "zacgs.h"

#include "zinetstrc.h"

#include "zacsymutl.h"
#include "zdbxEntryPoint.h"

#ifdef _DBX_HOST_APPLICATION_
#include "ztruetypetext.h"
#include "zdbhaext.h"
#include "zacdbxref.h"
#endif

#ifdef _BREP_SUPPORT_
#include "brbctrav.h"
#include "brbetrav.h"
#include "brbftrav.h"
#include "brbrep.h"
#include "brbstrav.h"
#include "brbvtrav.h"
#include "brcplx.h"
#include "brcstrav.h"
#include "bredge.h"
#include "brelem.h"
#include "brelem2d.h"
#include "breltrav.h"
#include "brent.h"
#include "brentrav.h"
#include "brface.h"
#include "brfltrav.h"
#include "brgbl.h"
#include "brhit.h"
#include "brletrav.h"
#include "brloop.h"
#include "brlvtrav.h"
#include "brm2dctl.h"
#include "brmctl.h"
#include "brment.h"
#include "brmesh.h"
#include "brmesh2d.h"
#include "brmetrav.h"
#include "brnode.h"
#include "brprops.h"
#include "brsftrav.h"
#include "brshell.h"
#include "brtrav.h"
#include "brvetrav.h"
#include "brvltrav.h"
#include "brvtx.h"
#endif

#ifdef _HLR_SUPPORT_
#include "Hlr.h"
#include "BasePex.h"
#endif

#ifdef _AMODELER_SUPPORT_
#include "zamodeler.h"
#include "zbody.h"
#include "zcallback.h"
#include "zcheck.h"
#include "zcircle3d.h"
#include "zcolor.h"
#include "zcurve.h"
#include "zdarray.h"
#include "zdeviat.h"
#include "zdxfinpln.h"
#include "zdxfout.h"
#include "zedge.h"
#include "zentity.h"
#include "zenums.h"
#include "zepsilon.h"
#include "zerrcodes.h"
#include "zface.h"
#include "zflags.h"
#include "zglobal.h"
#include "zinterval.h"
#include "zipoint2d.h"
#include "zipoint3d.h"
#include "zivect2d.h"
#include "zivect3d.h"
#include "zline3d.h"
#include "zmassert.h"
#include "zmorphmap.h"
#include "zplane.h"
#include "zpoint2d.h"
#include "zpoint3d.h"
#include "zsurface.h"
#include "ztransf3d.h"
#include "zutil.h"
#include "zvector2d.h"
#include "zvector3d.h"
#include "zvertdata.h"
#include "zvertex.h"
#include "zvertsurf.h"
#include "zwallcrnr.h"
#endif

#pragma pack (pop)
