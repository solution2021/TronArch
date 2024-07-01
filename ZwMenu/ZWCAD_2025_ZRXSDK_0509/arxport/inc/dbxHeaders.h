﻿
#ifndef __DBXHEADERS_H__
#define __DBXHEADERS_H__

//----- Rx Kernels
#include "acmem.h"
#include "adesk.h"
#include "adeskabb.h"
#include "acadstrc.h"
#include "rxdefs.h"
#include "rxnames.h"
#include "rxboiler.h"
#include "rxclass.h"
#include "AcDbClassIter.h"
#include "rxdict.h"
#include "rxobject.h"
#include "rxsrvice.h"
#include "rxkernel.h"
#include "rxdlinkr.h"
#include "rxregsvc.h"
#include "rxevent.h"
#include "rxiter.h"
#include "rxditer.h"
#include "appinfo.h"
#include "rxprotevnt.h"

//----- Rx Un-Classified
#include "PAL/api/codepgid.h"
#include "AcHeapOpers.h"
#include "AcString.h"
#include "AdAChar.h"
#include "acly.h"

//----- Db sub-system
#include "acarray.h"
#include "dbhandle.h"
#include "dbid.h"
#include "dbidar.h"
#include "dbcolor.h"
#include "dbptrar.h"
#include "drawable.h"
#include "dbsecurity.h"
#include "dbboiler.h"
#include "acdb.h"
#include "acdbabb.h"
#include "dbAlignment.h"
#include "dbfiler.h"
#include "dbintar.h"
#include "dbsubeid.h"
#include "dbaudita.h"
#include "dbmain.h"
#include "dbdict.h"
#include "dbdate.h"
#include "dbsymtb.h"
#include "dbsymutl.h"
#include "dbdictdflt.h"
#include "dbDictUtil.h"
#include "dbcurve.h"
#include "dbmtext.h"
#include "dbdim.h"
#include "dbDimData.h"
#include "dbents.h"
#include "dbeval.h"
#include "AcField.h"
#include "DbField.h"
#include "dbtable.h"
#include "dbTableStyle.h"
#include "dbdynblk.h"
#include "dbproxy.h"
#include "dbfcf.h"
#include "dbapserv.h"
#include "dbgroup.h"
#include "dbhatch.h"
#include "dblead.h"
#include "dbelipse.h"
#include "dbspline.h"
#include "dbray.h"
#include "dbsol3d.h"
#include "dbregion.h"
#include "dbacis.h"
#include "dbbody.h"
#include "dbframe.h"
#include "dbole.h"
#include "imgdef.h"
#include "imgvars.h"
#include "dbimage.h"
#include "imgent.h"
#include "dblstate.h"
#include "dbmstyle.h"
#include "dbmline.h"
#include "dbxline.h"
#include "dbxrecrd.h"
#include "achapi.h"
#include "dbDataTable.h"
#include "dbfilter.h"
#ifndef _MANAGED
#include "dbgrip.h"
#endif
#include "dbappgrip.h"
#include "dbidmap.h"
#include "dbindex.h"
#include "dblaymgrrctr.h"
#include "dblayout.h"
#include "dbmaterial.h"
#include "dbpl.h"
#include "dbtrans.h"
#include "sorttab.h"
#include "xreflock.h"

//----- Db utils
#include "acgiutil.h"
#include "dbcfilrs.h"
#include "dblyfilt.h"
#include "dblyindx.h"
#include "dbspfilt.h"
#include "dbspindx.h"
#include "dbplhldr.h"
#include "dbxutil.h"
#include "idgraph.h"
#include "summinfo.h"
#include "textengine.h"
#include "graph.h"
#include "xgraph.h"
#include "dbplotsettings.h"
#include "dbplotsetval.h"
#include "AcDbLMgr.h"
#include "acappvar.h"

#include "acgi.h"
#include "AcGiLineAttributes.h"
#include "AcGiLineAttrUtils.h"
#include "acgimaterial.h"
#include "AcGiStyleAttributes.h"
#include "linetypeengine.h"

#include "acutil.h"
#include "acestext.h"
#include "adsdef.h"
#include "acdbads.h"
#include "acutads.h"
#include "ads.h"
#include "adscodes.h"
#include "adsmigr.h"
#include "migrtion.h"

#include "dbobjptr.h"

#include "geassign.h"
#include "geblok2d.h"
#include "geblok3d.h"
#include "geell2d.h"
#include "geell3d.h"
#include "gecone.h"
#include "gecylndr.h"
#include "gesphere.h"
#include "getorus.h"
#include "geray2d.h"
#include "geray3d.h"
#include "gessint.h"
#include "gedwgio.h"
#include "gedxfio.h"
#include "gefiler.h"
#include "gecspl2d.h"
#include "gecspl3d.h"
#include "gepos2d.h"
#include "gepos3d.h"
#include "geoffc2d.h"
#include "geoffc3d.h"
#include "geoffsf.h"
#include "genurb2d.h"
#include "genurb3d.h"
#include "genurbsf.h"	
#include "gecsint.h"
#include "geextc2d.h"
#include "geextc3d.h"
#include "geextsf.h"
#include "gecomp2d.h"
#include "gecomp3d.h"
#include "gecint2d.h"
#include "gecint3d.h"
#include "gescl2d.h"
#include "gescl3d.h"
#include "geclip2d.h"
#include "gexbndsf.h"
#include "gecbndry.h"
#include "geapln3d.h"
#include "gearc2d.h"
#include "gearc3d.h"
#include "gebndpln.h"
#include "gecurv2d.h"
#include "gecurv3d.h"
#include "gedblar.h"
#include "gedll.h"
#include "geent2d.h"
#include "geent3d.h"
#include "gefileio.h"
#include "gegbl.h"
#include "gegblabb.h"
#include "gegblge.h"
#include "gegblnew.h"
#include "geintarr.h"
#include "geintrvl.h"
#include "gekvec.h"
#include "gelent2d.h"
#include "gelent3d.h"
#include "gelibver.h"
#include "geline2d.h"
#include "geline3d.h"
#include "gelnsg2d.h"
#include "gelnsg3d.h"
#include "gemat2d.h"
#include "gemat3d.h"
#include "gepent2d.h"
#include "gepent3d.h"
#include "geplanar.h"
#include "geplane.h"
#include "geplin2d.h"
#include "geplin3d.h"
#include "gepnt2d.h"
#include "gepnt3d.h"
#include "geponc2d.h"
#include "geponc3d.h"
#include "geponsrf.h"
#include "gept2dar.h"
#include "gept3dar.h"
#include "gesent2d.h"
#include "gesent3d.h"
#include "gesurf.h"
#include "getol.h"
#include "gevc2dar.h"
#include "gevc3dar.h"
#include "gevec2d.h"
#include "gevec3d.h"
#include "gevptar.h"

#ifdef _MANAGED
#include <vcclr.h>
#include "mgdinterop.h"
#endif


#ifdef __ATLCOM_H__
#ifndef _ACRXAPP
#include "../inc-x64/axdb.h"
#else
#include "acadi.h"
#endif // _ACRXAPP
#include "oleaprot.h"
#include "category.h"
#include "axobjref.h"
#include "axboiler.h"
#include "../inc-x64/acpi.h"
#include "opmdialog.h"
#include "opmimp.h"
#include "opmdrvr.h"
#include "opmext.h"
#include "axtempl.h"
#include "axpnt2d.h"
#include "axpnt3d.h"
#include "axmat3d.h"
#include "axlock.h"
#include "dynprops.h"
#include "../inc-x64/acpexctl.h"
#include "../inc-x64/AcPp.h"
#endif // __ATLCOM_H__

#include "acut.h"
#include "acutmem.h"
#include "acutmigr.h"

#include "acgs.h"		

#include "inetstrc.h"

#include "acsymutl.h"	
#include "dbxEntryPoint.h"

#ifdef _DBX_HOST_APPLICATION_
#include "truetypetext.h"
#include "acdbxref.h"
#endif // _DBX_HOST_APPLICATION_

#ifdef _BREP_SUPPORT_
#include "../utils/brep/inc/brbctrav.h"
#include "../utils/brep/inc/brbetrav.h"
#include "../utils/brep/inc/brbftrav.h"
#include "../utils/brep/inc/brbrep.h"
#include "../utils/brep/inc/brbstrav.h"
#include "../utils/brep/inc/brbvtrav.h"
#include "../utils/brep/inc/brcplx.h"
#include "../utils/brep/inc/brcstrav.h"
#include "../utils/brep/inc/bredge.h"
#include "../utils/brep/inc/brelem.h"
#include "../utils/brep/inc/brelem2d.h"
#include "../utils/brep/inc/breltrav.h"
#include "../utils/brep/inc/brent.h"
#include "../utils/brep/inc/brentrav.h"
#include "../utils/brep/inc/brface.h"
#include "../utils/brep/inc/brfltrav.h"
#include "../utils/brep/inc/brgbl.h"
#include "../utils/brep/inc/brhit.h"
#include "../utils/brep/inc/brletrav.h"
#include "../utils/brep/inc/brloop.h"
#include "../utils/brep/inc/brlvtrav.h"
#include "../utils/brep/inc/brm2dctl.h"
#include "../utils/brep/inc/brmctl.h"
#include "../utils/brep/inc/brment.h"
#include "../utils/brep/inc/brmesh.h"
#include "../utils/brep/inc/brmesh2d.h"
#include "../utils/brep/inc/brmetrav.h"
#include "../utils/brep/inc/brnode.h"
#include "../utils/brep/inc/brprops.h"
#include "../utils/brep/inc/brsftrav.h"
#include "../utils/brep/inc/brshell.h"
#include "../utils/brep/inc/brtrav.h"
#include "../utils/brep/inc/brvetrav.h"
#include "../utils/brep/inc/brvltrav.h"
#include "../utils/brep/inc/brvtx.h"
#endif // _BREP_SUPPORT_

#ifdef _HLR_SUPPORT_
#include "../utils/HlrApi/inc/Hlr.h"
#include "../utils/HlrApi/inc/BasePex.h"
#endif // _HLR_SUPPORT_

#ifdef _AMODELER_SUPPORT_
#include "../utils/amodeler/inc/amodeler.h"
#include "../utils/amodeler/inc/body.h"
#include "../utils/amodeler/inc/callback.h"
#include "../utils/amodeler/inc/check.h"
#include "../utils/amodeler/inc/circle3d.h"
#include "../utils/amodeler/inc/color.h"
#include "../utils/amodeler/inc/curve.h"
#include "../utils/amodeler/inc/darray.h"
#include "../utils/amodeler/inc/deviat.h"
#include "../utils/amodeler/inc/dxfinpln.h"
#include "../utils/amodeler/inc/dxfout.h"
#include "../utils/amodeler/inc/edge.h"
#include "../utils/amodeler/inc/entity.h"
#include "../utils/amodeler/inc/enums.h"
#include "../utils/amodeler/inc/epsilon.h"
#include "../utils/amodeler/inc/errcodes.h"
#include "../utils/amodeler/inc/face.h"
#include "../utils/amodeler/inc/flags.h"
#include "../utils/amodeler/inc/global.h"
#include "../utils/amodeler/inc/interval.h"
#include "../utils/amodeler/inc/ipoint2d.h"
#include "../utils/amodeler/inc/ipoint3d.h"
#include "../utils/amodeler/inc/ivect2d.h"
#include "../utils/amodeler/inc/ivect3d.h"
#include "../utils/amodeler/inc/line3d.h"
#include "../utils/amodeler/inc/massert.h"
#include "../utils/amodeler/inc/morphmap.h"
#include "../utils/amodeler/inc/plane.h"
#include "../utils/amodeler/inc/point2d.h"
#include "../utils/amodeler/inc/point3d.h"
#include "../utils/amodeler/inc/surface.h"
#include "../utils/amodeler/inc/transf3d.h"
#include "../utils/amodeler/inc/util.h"
#include "../utils/amodeler/inc/vector2d.h"
#include "../utils/amodeler/inc/vector3d.h"
#include "../utils/amodeler/inc/vertdata.h"
#include "../utils/amodeler/inc/vertex.h"
#include "../utils/amodeler/inc/vertsurf.h"
#include "../utils/amodeler/inc/wallcrnr.h"
#endif // _AMODELER_SUPPORT_

#include "../../inc/zdbxHeaders.h"


#ifndef AC_FULL_DEBUG
#define AC_FULL_DEBUG		ZC_FULL_DEBUG
#endif //#ifndef AC_FULL_DEBUG


#endif //#ifndef __DBXHEADERS_H__
