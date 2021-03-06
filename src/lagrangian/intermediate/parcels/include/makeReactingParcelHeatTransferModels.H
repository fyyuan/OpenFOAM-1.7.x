/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2008-2010 OpenCFD Ltd.
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

\*---------------------------------------------------------------------------*/

#ifndef makeReactingParcelHeatTransferModels_H
#define makeReactingParcelHeatTransferModels_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "thermoPhysicsTypes.H"
#include "ThermoCloud.H"

#include "NoHeatTransfer.H"
#include "RanzMarshall.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeReactingHeatTransferModels(ParcelType)                            \
                                                                              \
    makeReactingHeatTransferModelThermoType                                   \
    (                                                                         \
        ParcelType,                                                           \
        constGasThermoPhysics                                                 \
    );                                                                        \
    makeReactingHeatTransferModelThermoType                                   \
    (                                                                         \
        ParcelType,                                                           \
        gasThermoPhysics                                                      \
    );                                                                        \
    makeReactingHeatTransferModelThermoType                                   \
    (                                                                         \
        ParcelType,                                                           \
        icoPoly8ThermoPhysics                                                 \
    );


#define makeReactingHeatTransferModelThermoType(ParcelType, ThermoType)       \
                                                                              \
    makeHeatTransferModel(ThermoCloud<ParcelType<ThermoType> >);              \
                                                                              \
    makeHeatTransferModelThermoType                                           \
    (                                                                         \
        NoHeatTransfer,                                                       \
        ThermoCloud,                                                          \
        ParcelType,                                                           \
        ThermoType                                                            \
    );                                                                        \
    makeHeatTransferModelThermoType                                           \
    (                                                                         \
        RanzMarshall,                                                         \
        ThermoCloud,                                                          \
        ParcelType,                                                           \
        ThermoType                                                            \
    );


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
