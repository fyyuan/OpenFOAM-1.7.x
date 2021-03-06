/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 1991-2010 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Primitive
    bool

Description
    System bool

SourceFiles
    boolIO.C

\*---------------------------------------------------------------------------*/

#ifndef bool_H
#define bool_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class Istream;
class Ostream;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

Istream& operator>>(Istream&, bool&);
Ostream& operator<<(Ostream&, const bool);

bool readBool(Istream&);

} // End namespace Foam


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "pTraits.H"

namespace Foam
{

// template specialisation for pTraits<bool>
template<>
class pTraits<bool>
{
    bool p_;

public:

    //- Component type
    typedef bool cmptType;

    // Member constants

        enum
        {
            dim = 3,         // Dimensionality of space
            rank = 0,        // Rank of bool is 0
            nComponents = 1  // Number of components in bool is 1
        };


    // Static data members

        static const char* const typeName;
        static const char* componentNames[];
        static const bool zero;
        static const bool one;


    // Constructors

        //- Construct from bool
        pTraits(const bool b)
        {
            p_ = b;
        }

        //- Construct from Istream
        pTraits(Istream&);


    // Member Functions

        operator bool() const
        {
            return p_;
        }

        operator bool&()
        {
            return p_;
        }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
