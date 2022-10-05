#!/bin/bash
#SBATCH --chdir /scratch/<username>
#SBATCH --nodes 1
#SBATCH --ntasks 1
#SBATCH --cpus-per-task 1
#SBATCH --mem 1G

echo STARTING AT `date`

./pi 4 100000000

echo FINISHED at `date`
