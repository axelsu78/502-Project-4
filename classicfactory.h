#pragma once

#include "moviefactory.h"
#include "movieparams.h"
#include "classicmovie.h"

class ClassicFactory : public MovieFactory{

public:

   ClassicFactory();

   std::shared_ptr<Movie> createMovie(const MovieParams& params) override;

   std::shared_ptr<Movie> createSearchKey(const MovieParams& params) override;

};