/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2006 StatPro Italia srl

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


#ifndef quantlib_market_model_parametric_exercise_adapter_hpp
#define quantlib_market_model_parametric_exercise_adapter_hpp

#include <ql/methods/montecarlo/exercisestrategy.hpp>
#include <ql/utilities/clone.hpp>
#include <valarray>

namespace QuantLib {

    class CurveState;
    class MarketModelParametricExercise;

    class ParametricExerciseAdapter : public ExerciseStrategy<CurveState> {
      public:
        ParametricExerciseAdapter(
                           const MarketModelParametricExercise& exercise,
                           const std::vector<std::vector<Real> >& parameters);
        std::vector<Time> exerciseTimes() const;
        std::vector<Time> relevantTimes() const;
        void reset();
        void nextStep(const CurveState& currentState);
        bool exercise(const CurveState& currentState) const;
        #if defined(QL_USE_STD_UNIQUE_PTR)
        std::unique_ptr<ExerciseStrategy<CurveState> > clone() const;
        #else
        std::auto_ptr<ExerciseStrategy<CurveState> > clone() const;
        #endif
      private:
        Clone<MarketModelParametricExercise> exercise_;
        std::vector<std::vector<Real> > parameters_;
        std::vector<Time> exerciseTimes_;
        Size currentStep_, currentExercise_;
        std::valarray<bool> isExerciseTime_;
        std::vector<Size> numberOfVariables_;
        mutable std::vector<Real> variables_;
    };

}


#endif
