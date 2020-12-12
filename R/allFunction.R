rowcolttestsR <- function(Cx, Cfac, Cnrgrp, Cwhich, Cna_rm){
  .Call("rowcolttests", Cx, Cfac, Cnrgrp, Cwhich, Cna_rm)
}
