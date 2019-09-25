int availableMemory() {
	// Use 1024 with ATmega168
	int size = 2048;
	byte *buf;
	while ((buf = (byte *)malloc(--size)) == NULL);
	free(buf);
	return size;
}



int freeRam() {
	extern int __heap_start, *__brkval;
	int v;
	return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}
