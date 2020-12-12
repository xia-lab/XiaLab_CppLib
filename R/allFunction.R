rowcolttestsR <- function(Cx, Cfac, Cnrgrp, Cwhich, Cna_rm){
  .Call("rowcolttests", 
        Cx, Cfac, Cnrgrp, Cwhich, Cna_rm)
}

do_decoranaR <- function(Cveg, Cira, Ciresc, Crshort, Cimk, Caidot, Cadotj){
  .Call("do_decorana", 
        Cveg, Cira, Ciresc, Crshort, Cimk, Caidot, Cadotj)
}

imodwtR <- function(Cwin, Cvin, Cn, Cj, Cl, Cht, Cgt, Cvout){
  .C("imodwt", 
     Cwin, Cvin, Cn, Cj, Cl, Cht, Cgt, Cvout)
}

modwtR <- function(Cyvals, Cnumin, Cistart, Cilower, Ciupper){
  .C("modwt", 
     Cyvals, Cnumin, Cistart, Cilower, Ciupper)
}

DescendMinR <- function(Cyvals, Cnumin, Cistart, Cilower, Ciupper){
  .C("DescendMinR", 
     Cyvals, Cnumin, Cistart, Cilower, Ciupper)
}

FindEqualGreaterMR <- function(Cin, Csize, Cvalues, Cvalsize, Cindex){
  .C("FindEqualGreaterMR", 
     Cin, Csize, Cvalues, Cvalsize, Cindex)
}

RectUniqueR <- function( Cm, Corder,  Cnrow, Cncol, Cxdiff,  Cydiff, Ckeep){
  .C("RectUniqueR",
  Cm, Corder,  Cnrow, Cncol, Cxdiff,  Cydiff, Ckeep)
}
