#include "s21_matrix.h"

/// @brief Выделяет память под матрицу(matrix) размером rows на columns
/// и задает эти параметры(rows, columns и matrix) структуре result
/// @param rows кол-во строк
/// @param columns кол-во столбцов
/// @param result созданная матрица из строк и столбцов
/// @return 0 - без ошибок, 1 - некорректная матрица
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error_code = 0;

  if (columns > 0 && rows > 0) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
    }
  } else {
    error_code = 1;
  }

  return error_code;
}

/// @brief Особождает память матрицы А
/// @param A матрица для удаления
void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->matrix = NULL;
  A->columns = 0;
  A->rows = 0;
}

/// @brief Сравнивает равенство матриц A и B
/// @param A первая матрица
/// @param B вторая матрица
/// @return 1 - равны, 0 - не равны
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;

  if (A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns && result; j++) {
        result = s21_eq_double(A->matrix[i][j], B->matrix[i][j]);
      }
    }
  } else {
    result = FAILURE;
  }

  return result;
}

/// @brief Суммирует матрицу A с матрицей B
/// @param A первая матрица
/// @param B вторая матрица
/// @param result результирующая матрица
/// @return 0 - без ошибок, 1 - некорректная матрица, 2 - вычислительная ошибка
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = 0;

  error_code = s21_is_matrix_correct(A);
  if (error_code == 0) {
    error_code = s21_is_matrix_correct(B);
  }
  if (error_code == 0) {
    if (A->columns != B->columns || A->rows != B->rows) {
      error_code = 2;
    }
  }
  if (error_code == 0) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return error_code;
}

/// @brief Вычитает из матрицы A матрицу B
/// @param A первая матрица
/// @param B вторая матрица
/// @param result результирующая матрица
/// @return 0 - без ошибок, 1 - некорректная матрица, 2 - вычислительная ошибка
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = 0;

  error_code = s21_is_matrix_correct(A);
  if (error_code == 0) {
    error_code = s21_is_matrix_correct(B);
  }
  if (error_code == 0) {
    if (A->columns != B->columns || A->rows != B->rows) {
      error_code = 2;
    }
  }
  if (error_code == 0) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return error_code;
}

/// @brief Умножает все элементы матрицы A на множитель number
/// @param A матрица
/// @param number множитель
/// @param result результирующая матрица
/// @return 0 - без ошибок, 1 - некорректная матрица
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error_code = 0;

  error_code = s21_is_matrix_correct(A);
  if (error_code == 0) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return error_code;
}

/// @brief Умножает матрицу A на матрицу B
/// @param A первая матрица
/// @param B вторая матрица
/// @param result результирующая матрица
/// @return 0 - без ошибок, 1 - некорректная матрица, 2 - вычислительная ошибка
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = 0;

  error_code = s21_is_matrix_correct(A);
  if (error_code == 0) {
    error_code = s21_is_matrix_correct(B);
  }
  if (error_code == 0) {
    if (A->columns != B->rows) {
      error_code = 2;
    }
  }
  if (error_code == 0) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] =
              result->matrix[i][j] + A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return error_code;
}

/// @brief Транспонирует матрицу A
/// @param A матрица
/// @param result транспонированная матрица
/// @return 0 - без ошибок, 1 - некорректная матрица
int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_code = 0;

  error_code = s21_is_matrix_correct(A);
  if (error_code == 0) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return error_code;
}

/// @brief Вычисляет матрицу алгебраических дополнений result из матрицы A
/// @param A матрица
/// @param result матрица алгебраических дополнений
/// @return 0 - без ошибок, 1 - некорректная матрица
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error_code = 0;

  error_code = s21_is_matrix_correct(A);
  if (error_code == 0) {
    if (A->columns != A->rows) {
      error_code = 2;
    }
  }
  if (error_code == 0) {
    s21_create_matrix(A->columns, A->rows, result);
    if (A->columns == 1) {
      result->matrix[0][0] = A->matrix[0][0];
    } else if (A->columns > 1) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          double tmp_result = 0;
          matrix_t tmp_matrix;
          s21_create_matrix(A->rows - 1, A->columns - 1, &tmp_matrix);
          for (int k = 0, m = 0; k < A->rows - 1; k++, m++) {
            for (int l = 0, n = 0; l < A->columns - 1; l++, n++) {
              if (m == i) {
                m++;
              }
              if (n == j) {
                n++;
              }
              tmp_matrix.matrix[k][l] = A->matrix[m][n];
            }
          }
          s21_determinant(&tmp_matrix, &tmp_result);
          result->matrix[i][j] = (1 - 2 * ((i + j) % 2)) * tmp_result;
          s21_remove_matrix(&tmp_matrix);
        }
      }
    }
  }

  return error_code;
}

/// @brief Вычисляет определитель result для матрицы A
/// @param A матрица
/// @param result определитель матрицы
/// @return 0 - без ошибок, 1 - некорректная матрица, 2 - вычислительная ошибка
int s21_determinant(matrix_t *A, double *result) {
  int error_code = 0;

  *result = 0;
  error_code = s21_is_matrix_correct(A);
  if (error_code == 0) {
    if (A->columns != A->rows) {
      error_code = 2;
    }
  }
  if (error_code == 0) {
    if (A->columns == 1) {
      *result = A->matrix[0][0];
    } else {
      for (int k = 0; k < A->columns; k++) {
        double tmp_result = 0;
        matrix_t tmp_matrix;
        s21_create_matrix(A->rows - 1, A->columns - 1, &tmp_matrix);
        for (int i = 0; i < A->rows - 1; i++) {
          for (int j = 0, x = 0; j < A->columns - 1; j++, x++) {
            if (x == k) {
              x++;
            }
            tmp_matrix.matrix[i][j] = A->matrix[i + 1][x];
          }
        }
        s21_determinant(&tmp_matrix, &tmp_result);
        *result += (1 - 2 * (k % 2)) * tmp_result * A->matrix[0][k];
        s21_remove_matrix(&tmp_matrix);
      }
    }
  }

  return error_code;
}

/// @brief Находит обратную матрицу result к матрице A
/// @param A матрица
/// @param result обратная матрица
/// @return 0 - без ошибок, 1 - некорректная матрица, 2 - вычислительная ошибка
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_code = 0;
  double determinant = 0;

  if (A == NULL || A->rows < 1 || A->columns < 1) {
    error_code = 1;
  } else if (A->columns != A->rows) {
    error_code = 2;
  } else if (!s21_determinant(A, &determinant) && !determinant) {
    error_code = 2;
  } else {
    matrix_t complements, transpose;
    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &transpose);
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = 1 / determinant * transpose.matrix[i][j];
      }
    }
    s21_remove_matrix(&complements);
    s21_remove_matrix(&transpose);
  }
  return error_code;
}

/// @brief Определяет корректность матрицы
/// @param A матрица
/// @return 0 - без ошибок, 1 - некорректная матрица
int s21_is_matrix_correct(matrix_t *A) {
  int error_code = 1;

  if (A != NULL && A->columns > 0 && A->rows > 0) {
    error_code = 0;
  }

  return error_code;
}

/// @brief сравнивает равенство чисел типа double до 7 знаков после запятой
/// включительно
/// @param value1 первое число
/// @param value2 второе число
/// @return 1 - равны, 0 - не равны
int s21_eq_double(double value1, double value2) {
  int result = SUCCESS;

  if ((long int)value1 >> 63 == (long int)value2 >> 63) {
    double inequality = value1 - value2;
    if (inequality < 0) {
      inequality *= -1;
    }
    if (inequality >= 0.0000001) {
      result = FAILURE;
    }
  } else {
    result = FAILURE;
  }

  return result;
}
