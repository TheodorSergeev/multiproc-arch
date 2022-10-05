#!/bin/bash
#SBATCH --chdir /home/fsergeev/multiproc-arch/A1
#SBATCH --nodes 1
#SBATCH --ntasks 1
#SBATCH --cpus-per-task 1
#SBATCH --time 00:05:00
#SBATCH --mem 256MB

for THREADS in 1, 2, 4, 8
do
    echo STARTING AT `date`
    ./pi $THREADS 100000000
    echo FINISHED at `date`
done
