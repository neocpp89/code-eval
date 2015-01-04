#!/usr/bin/env Rscript

argv <- commandArgs(TRUE)
data <- t(read.table(argv[1], header=FALSE))
s <- rev(dim(data))
v <- 1:s[1]
# print(data)
#d <- t(data)
invisible(gc(FALSE))
# print(d)
# X11()
for (i in v) {
    t <- 1:s[2]
    dr <- data[,i]
    eq.out = lm(dr ~ t)
    c = coefficients(eq.out)
    dr <- (dr - c[1] - c[2]*t)
    # print(dr)
    fdr <- fft(dr)
    p <- abs(fdr[1:s[2]/2])
    f <- 1:s[2]/2
    # plot(f, p)
    # plot(t, dr)
    domfreq <- which(p == max(p))
    domfreq <- 10 * (domfreq - 1)/2
    str <- sprintf("%d", as.vector(domfreq[1]))
    write(str,"")
    # invisible(readLines("stdin", n=1))
    gc()
}
# message("Press Return To Continue")
# invisible(readLines("stdin", n=1))
