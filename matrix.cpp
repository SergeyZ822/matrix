#include <iostream>

int* alloc_ints(int size)
{
    try
    {
        return new int[size];
    }
    catch (...)
    {
        return nullptr;
    }
}

int** alloc_ptrs(int size)
{
    try
    {
        return new int*[size];
    }
    catch (...)
    {
        return nullptr;
    }
}

void delete_matrix(int** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }

    delete[] a;
}

int** create_matrix(int n, int m)
{
    int** a = alloc_ptrs(n);

    if (a == nullptr)
    {
        return nullptr;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = alloc_ints(m);

        if (a[i] == nullptr)
        {
            delete_matrix(a, i);
            return nullptr;
        }
    }

    return a;
}

int main()
{
    int n, m;

    if (!(std::cin >> n >> m) || n <= 0 || m <= 0)
    {
        return 1;
    }

    int** a = create_matrix(n, m);

    if (a == nullptr)
    {
        return 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!(std::cin >> a[i][j]))
            {
                delete_matrix(a, n);
                return 1;
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
            {
                std::cout << " ";
            }

            std::cout << a[i][j];
        }

        std::cout << "\n";
    }

    delete_matrix(a, n);

    return 0;
}
