#!/bin/bash
rm -f Benchmarks/Polybench/poly_tiled/*
touch Benchmarks/Polybench/poly_tiled/results.txt
rm -f Benchmarks/Polybench/poly_tiling/generated/*.tpips
rm -f Benchmarks/Polybench/poly_tiling/generated/*.txt
source /home/maksim/Documents/MYPIPS/pipsrc-prod.sh
python3 tiling_pipeline.py