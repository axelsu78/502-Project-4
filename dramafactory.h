#pragma once

#include "moviefactory.h"
#include "movieparams.h"

class DramaFactory : public MovieFactory{

public:

   DramaFactory();

   std::shared_ptr<Movie> createMovie(const MovieParams& params) override;

   std::shared_ptr<Movie> createSearchKey(const MovieParams& params) override;

};