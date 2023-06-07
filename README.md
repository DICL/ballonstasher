# BallonStasher
This document describes the artifact for BallonStasher.
The remainder of this document describes how to run BallonStasher and reproduce the results from our paper.
If you are looking for some guidance on how to test new systems with BallonStasher, please follow as below.

## Dependencies

- Install packages

```bash
sudo apt install librdmacm-dev libibverbs-dev cmake jemalloc
```

- RDMA NIC driver: MLNX_OFED v5.1 or Linux inbox driver

## System Configurations

The artifact was tested in a five machines with following specifications:

- Ubuntu 18.04
- Linux kernel v5.4
- two 10-core Intel(R) Xeon(R) Gold 5215 CPU @ 2.50GHz
- 8 x 16 GB DDR4 DRAM
- Samsung 860 EVO 500 GB SATA SSD
- Mellanox Technologies MT27700 Family [ConnectX-4]

## Compiling and Reproducing Results

### Compiling Driver and Daemon
```bash
cd driver && ./build.sh
cd daemon && ./build.sh
```

## Notes
- If your system resources (e.g., CPU, SSD and RNIC) are different from the paper, the experimental results may also be different.
