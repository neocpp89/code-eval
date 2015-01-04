#!/usr/bin/env Rscript

argv <- commandArgs(TRUE)
ff <- argv[1]
con <- file(description=ff, open="r")
# X11()
while ((ssl <- length(std <- scan(con, nlines=1, quiet=TRUE))) > 0) {
    # print(std)
    # print(ssl)
    s = ssl
    t <- 1:ssl
    dr <- std
    eq.out = lm(dr ~ t)
    c = coefficients(eq.out)
    dr <- (dr - c[1] - c[2]*t)
    # print(dr)
    fdr <- fft(dr)
    p <- abs(fdr[1:ssl/2])
    f <- 1:ssl/2
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
