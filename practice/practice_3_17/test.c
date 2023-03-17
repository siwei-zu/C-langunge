#define _CRT_SECURE_NO_WARNINGS 1
#define max(a,b) a > b ? a : b 

int captureForts(int* forts, int fortsSize) {
    int ans = 0;
    for (int j = 0; j < fortsSize; j++) {
        if (forts[j] == -1 || forts[j] == 0) continue;
        //����ɨ
        int i = j - 1;//�Ӵ�ʱ1��ߵ����꿪ʼ
        while (i >= 0 && forts[i] == 0) i--;//�����һֱ����߽߱�ǰ��һֱ��С
        if (i >= 0 && forts[i] < 0) ans = max(ans, j - i - 1);//�������-1,�������

        //����ɨ
        i = j + 1;//�Ӵ�ʱ1�ұߵ����꿪ʼ
        while (i < fortsSize && forts[i] == 0) i++;//�����һֱ���ұ߽߱�ǰ��һֱ����
        if (i < fortsSize && forts[i] < 0) ans = max(ans, i - j - 1);
        //�������-1,�������
    }
    return ans;//���ؾ���
}
