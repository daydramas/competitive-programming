#ifndef __GRADER_H__
#define __GRADER_H__

#ifdef __cplusplus
extern "C" {
#endif

int best_path(int N, int K, int H[][2], int L[]);

typedef int (*best_pathFunction)(int N, int K, int H[][2], int L[]);

#ifdef __cplusplus
}
#endif

#endif /* __GRADER_H__ */
