/* app/src/matrix_transform_default.c
 * Implementação mínima padrão para zmk_matrix_transform_default
 * Define o struct localmente e provê a variável esperada pelo linker.
 */

#include <stdint.h>
#include <stddef.h>
#include <zephyr/sys/util.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/__assert.h>
#include <zephyr/sys/printk.h>

/* Inclui a declaração pública (se disponível no include path do projeto) */
#include <zmk/matrix_transform.h>

/* Definição do struct (mesma forma usada no código do ZMK) */
struct zmk_matrix_transform {
    const uint32_t *lookup_table;
    size_t len;
    uint8_t rows;
    uint8_t columns;
    uint8_t col_offset;
    uint8_t row_offset;
};

/* Se as macros de tamanho da matriz estiverem presentes, define o transform padrão.
 * Caso contrário, força um erro de compilação para sinalizar que algo está faltando nas configurações.
 */
#if defined(ZMK_MATRIX_ROWS) && defined(ZMK_MATRIX_COLS) && defined(ZMK_KEYMAP_LEN)

const struct zmk_matrix_transform zmk_matrix_transform_default = {
    .rows = ZMK_MATRIX_ROWS,
    .columns = ZMK_MATRIX_COLS,
    .col_offset = 0,
    .row_offset = 0,
    .len = ZMK_KEYMAP_LEN,
    .lookup_table = NULL,
};

#else
#error "ZMK_MATRIX_ROWS, ZMK_MATRIX_COLS ou ZMK_KEYMAP_LEN não estão definidas. Verifique seu board / overlay / config."
#endif
