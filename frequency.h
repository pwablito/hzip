struct FreqTable {
    int* table;
};

struct FreqTable create_frequency_table();

void destroy_frequency_table(struct FreqTable table);

int get_frequency(struct FreqTable table, const char byte);

void set_frequency(struct FreqTable table, char byte, int value);

struct FreqTable generate_frequencies(const char* buffer, int size);

void print_frequency_table(struct FreqTable table);
