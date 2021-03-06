/*---------------------------------------------------------------------------*\
License
    AeroSolved
    Copyright (C) 2017 Philip Morris International

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
\*---------------------------------------------------------------------------*/

/**

\file multiSpeciesFrederix.H
\brief Multi-species consistent model

Simple extension of the single-species condensation model into a multi-species
one. Based for some part on \cite Wilck:1997ab and \cite Friedlander:2000aa. It
adheres to two consistency conditions:

- When no molecules of species \f$j\f$ are present in the droplet and \f$Y_j =
  0\f$, \f$\mathrm{d}_ts_j\f$ (the rate of change of \f$j\f$-speciesmass of a
  droplet) must also be zero, since locally species \f$j\f$ is not present.

- If no molecules of species \f$j\f$ are present in the droplet, but \f$Y_j >
  0\f$, the droplet must be allowed to grow by accumulation of \f$j\f$ mass.

*/

#ifndef multiSpeciesFrederix_H
#define multiSpeciesFrederix_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace condensationEvaporationModels
{

/*---------------------------------------------------------------------------*\
                      Class multiSpeciesFrederix Declaration
\*---------------------------------------------------------------------------*/

class multiSpeciesFrederix
:
    public condensationEvaporationModel
{
    // Private data


    // Private Member Functions

        //- Disallow copy construct
        multiSpeciesFrederix(const multiSpeciesFrederix&);

        //- Disallow default bitwise assignment
        void operator=(const multiSpeciesFrederix&);


protected:

    // Protected data


public:

    //- Runtime type information
    TypeName("multiSpeciesFrederix");


    // Constructors

        //- Construct from components
        multiSpeciesFrederix(const fvMesh& mesh, aerosolModel& aerosol);


    //- Destructor
    virtual ~multiSpeciesFrederix();


    // Member Functions

        // Evolution

            List< List<scalar> > getCondRateListCell
            (
                const List<scalar>& z,
                const label jCell
            );

            List< List<scalar> > getEtaGammaListCell
            (
                const List<scalar>& z,
                const label jCell
            );

            //- Return droplet diameter for a given list of zetas and cell index
            List<scalar> psiInv
            (
                const List<scalar>& zeta,
                const label jCell
            );

        //  Access


        // I-O

            //- Update properties from given dictionary
            virtual bool read();
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace condensationEvaporationModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
