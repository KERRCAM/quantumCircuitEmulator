

/* IN MAIN FUNC */

    // matrix* a = newMatrix(2, 3);
    // matrix* b = newMatrix(3, 2);
    // double complex o = 1.0;
    // double complex n = 1.0;

    // for (int i = 0; i < a->h; i++){
    //     for (int j = 0; j < a->w; j++){
    //         a->mat[i * a->w + j] = n;
    //         n += o;
    //     }
    // }
    // for (int i = 0; i < b->h; i++){
    //     for (int j = 0; j < b->w; j++){
    //         b->mat[i * b->w + j] = n;
    //         n += o;
    //     }
    // }

    // printMatrix(a);
    // printf("\n");
    // printMatrix(b);
    // printf("\n");

    // matrix* result = matrixMult(a, b);
    // printMatrix(result);
    // printf("\n");

    // matrix* tr = matrixTranspose(result);
    // printMatrix(tr);
    // printf("\n");


    // matrix* q0 = newMatrix(2, 1);


    // matrix* H = newMatrix(2, 2);
    // H->mat[0] = 1.0 * sqrt(0.5);
    // H->mat[1] = 1.0 * sqrt(0.5);
    // H->mat[2] = 1.0 * sqrt(0.5);
    // H->mat[3] = -1.0 * sqrt(0.5);
    // // printMatrix(H);
    // // printf("\n");

    // matrix* q0 = newMatrix(2, 1);
    // q0->mat[0] = 1.0;
    // printMatrix(q0);
    // printf("\n");

    // matrix* q1 = newMatrix(2, 1);
    // q1->mat[0] = 1.0;
    // // q1 = matrixMult(H, q1);


    // q0 = matrixMult(H, q0);
    // printMatrix(q0);
    // printf("\n");

    // matrix* sv = tensorProduct(q1, q0);
    // printMatrix(sv);
    // printf("\n");


    // matrix* b0 = newMatrix(2, 1);
    // matrix* b1 = newMatrix(2, 1);

    // b0->mat[0] = 1.0;
    // b1->mat[1] = 1.0;
    // printMatrix(b0);
    // printf("\n");
    // printMatrix(b1);
    // printf("\n");

    // matrix* tp = tensorProduct(b0, b1);
    // printMatrix(tp);
    // printf("\n");

/*--------------------------------------------------------------------------------------------------------------------*/

/* IN GATE INIT FUNC */

    // matrix* result;
    // matrix* q0 = newMatrix(2, 1);
    // q0->mat[0] = 1.0;
    // matrix* q1 = newMatrix(2, 1);
    // q1->mat[0] = 1.0;

    // matrix* sv = tensorProduct(q0, q1);
    // printMatrix(sv);
    // printf("\n");

    // matrix* hxi = tensorProduct(hadamard, identity);
    // printMatrix(hxi);
    // printf("\n");

    // result = matrixMult(controlledNot, hxi);
    // printMatrix(result);
    // printf("\n");

    // result = matrixMult(result, sv);
    // printMatrix(result);
    // printf("\n");


    // result = matrixMult(hxi, sv);
    // printMatrix(result);
    // printf("\n");

    // result = matrixMult(controlledNot, result);
    // printMatrix(result);
    // printf("\n");


    // matrix* a = newMatrix(1, 2);
    // matrix* b = newMatrix(2, 1);
    // a->mat[0] = 1.0;
    // a->mat[1] = 2.0;
    // b->mat[0] = 3.0;
    // b->mat[1] = 4.0;
    // matrix* r = tensorProduct(a, b);
    // printMatrix(r);
