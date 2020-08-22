///////////////////////////////////////////////////////////////////////////////
// Name:        SpaceTransformTools.h
// Purpose:     Space transform utilities
// Author:      Vitaly Baranov
// Created:     April 19, 2009
// Modified by:  
// Licence:     GNU General Public License
///////////////////////////////////////////////////////////////////////////////

#ifndef __SpaceTransformTools__
#define __SpaceTransformTools__

struct UnitInfo
{
	int		setupUnit;
	LPCTSTR engUnitName;
	LPCTSTR localUnitName;
	float	cmsInUnit;
	UnitInfo(int setupUnit__, LPCTSTR engUnitName__, LPCTSTR localUnitName__, float cmsInUnit__)
	{
		setupUnit = setupUnit__;
		engUnitName = engUnitName__;
		localUnitName = localUnitName__;
		cmsInUnit = cmsInUnit__;
	}
};

size_t GetNumUnitInfos();
const UnitInfo& GetUnitInfo(size_t index);

void WriteSpaceTransformConfig(TSpaceTransform& spaceTransform);
void ReadSpaceTransformConfig(TSpaceTransform& spaceTransform);


#endif // __SpaceTransformTools__