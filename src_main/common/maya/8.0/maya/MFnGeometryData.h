
#ifndef _MFnGeometryData
#define _MFnGeometryData
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MFnGeometryData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnGeometryData)
// 
// This class is the function set for geometry data.
//
// Geometry data adds matrix and grouping (set) information to regular data
// and is used to pass geometry types such as mesh, lattice, and NURBS shape
// data through DG connections.
//
// User defined geometry data types (MPxGeometryData) are also supported 
// by this class.
//
// The matrix within geometry data is the matrix used to convert the object
// into local space.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MMatrix;

// *****************************************************************************

// CLASS DECLARATION (MFnGeometryData)

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

/// 
/**
*/
class OPENMAYA_EXPORT MFnGeometryData : public MFnData 
{

    declareMFn( MFnGeometryData, MFnData );

public:

    ///
    MStatus        setMatrix( const MMatrix & );
    ///
    MStatus        getMatrix ( MMatrix & ) const;
    ///
    bool           matrixIsIdentity( MStatus * ReturnStatus = NULL ) const;
    ///
    bool           matrixIsNotIdentity( MStatus * ReturnStatus = NULL ) const;
    
    // methods to add/remove object groups
    //
    ///
    bool           hasObjectGroup( unsigned int id,
                                   MStatus* ReturnStatus = NULL  ) const;
    ///
    MStatus        addObjectGroup( unsigned int );
    ///
    MStatus        removeObjectGroup( unsigned int );
    ///
    MStatus        changeObjectGroupId( unsigned int , unsigned int );

    // methods to get the i'th object group
    //
    ///
    unsigned int       objectGroupCount( MStatus * ReturnStatus = NULL ) const;
    ///
    unsigned int       objectGroup( unsigned int index,
                                MStatus* ReturnStatus = NULL ) const;

    // method to get the type of component stored by an object group
    //
    ///
    MFn::Type      objectGroupType( unsigned int,
                                    MStatus* ReturnStatus = NULL ) const;

    // methods to access and edit members of object group
    //
    ///
    MObject        objectGroupComponent( unsigned int,
                                         MStatus* ReturnStatus = NULL ) const;
    ///
    MStatus        setObjectGroupComponent( unsigned int, MObject & );
    ///
    MStatus        addObjectGroupComponent( unsigned int, MObject & );
    ///
    MStatus        removeObjectGroupComponent( unsigned int, MObject & );

    // Method to copy object groups from the geometry data sent in.
    //
    ///
    MStatus        copyObjectGroups( MObject & inGeom );


protected:
// No protected members

private:
// No Private members
 
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnGeometryData */
