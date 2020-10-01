#!/usr/bin/env python3
# -----------------------------------------------------------------------------
# @file generate_random_points.py
# @author Jacob Crabill <jacob@flyvoly.com>
# @date September 2020
# @brief Generates sets of test points for K-D Tree library
#
# For Volans-i's Fall 2020 Embedded Software Team Interview Exercise
# -----------------------------------------------------------------------------
import random
import sys

if len(sys.argv) < 3:
    print(f"Usage:\npython3 {sys.argv[0]} output_file.csv n_points")
    exit(0)

out_fname = str(sys.argv[1])
N = int(sys.argv[2])

outf = open(out_fname, 'w+')

outf.write(f"{N:d}\n")

random.seed("The world is on fire right now")

for i in range(N):
    x, y = random.uniform(-10, 10), random.uniform(-10, 10)
    outf.write(f"{x:.6f}, {y:.6f}\n")

outf.close()