/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2006 Ferdinando Ametrano

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/


#ifndef quantlib_multiproduct_onestep_hpp
#define quantlib_multiproduct_onestep_hpp

#include <ql/models/marketmodels/multiproduct.hpp>
#include <ql/models/marketmodels/evolutiondescription.hpp>

namespace QuantLib {

    //! Single-step market-model product
    /*! This is the abstract base class that encapsulates the notion
        of a MarketModelMultiProduct which can be evaluated in one step
        (aka Rebonato's very long jump).
    */
    class MultiProductOneStep : public MarketModelMultiProduct {
      public:
        explicit MultiProductOneStep(const std::vector<Time>& rateTimes);
        //! \name MarketModelMultiProduct interface
        //@{
        const EvolutionDescription& evolution() const;
        std::vector<Size> suggestedNumeraires() const;
        //@}
      protected:
        std::vector<Time> rateTimes_;
        EvolutionDescription evolution_;
    };

}

#endif
