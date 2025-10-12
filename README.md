# Homework 1: Matrix Multiplication Performance Comparison

## Overview
This project compares the performance of matrix multiplication across three different implementations:
- Pure C (compiled with gcc -O3)
- Pure Python (native loops)
- NumPy (optimized numerical library)

## Files Structure
```
.
├── matrix_mult.c           # C implementation
├── HW1_Report.ipynb        # Jupyter notebook with complete analysis
├── benchmark_results.csv   # Timing results data
└── README.md              # This file
```

## Requirements

### Software Requirements
- Python 3.8 or higher
- GCC compiler
- Jupyter Notebook

### Python Packages
```bash
!pip install numpy pandas matplotlib
```

## Installation & Setup

### 1. Clone or Download Files

#### If you want to run it on Google Colab 
1. Upload `Matrix_Multiplication_Report.ipynb` to your drive to use Google Colab.
2. Open the notebook in Colab.
3. **Runtime > Change runtime type** (optional): Keep Python 3 / GPU not required.

#### else you an see the instruction for Jupyter notebook below.

### 2. Compile C Program
```bash
gcc -O3 matrix_mult.c -o matrix_mult
```

**Verify compilation:**
```bash
./matrix_mult 64
```
You should see output like: `Execution time: 0.852 ms`

### 3. Install Python Dependencies
```bash
pip install numpy pandas matplotlib jupyter
```

## Running the Code

### Option 1: Run Complete Analysis (Jupyter Notebook)
```bash
jupyter notebook HW1_Report.ipynb
```

Then run all cells in the notebook.

### Option 2: Run Individual Components

#### Test C Implementation:
```bash
./matrix_mult 128
./matrix_mult 256
./matrix_mult 512
```

#### Test Python Implementation:
```python
python3 << EOF
from hw1_benchmark import time_python_multiplication
print(f"Python 64x64: {time_python_multiplication(64):.2f} ms")