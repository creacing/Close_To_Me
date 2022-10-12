

<template>
  <div
    id="imgs"
    :class="[isSun === 1 ? 'brand--image--white' : 'brand--image--dark']"
  ></div>
</template>
<script setup>
import { watch } from "vue";
import { store } from "@/stores/store.js";
import { storeToRefs } from "pinia";
const { isSun } = storeToRefs(store());
</script>
<style scoped lang='scss'>
.brand--image--white {
  background-image: linear-gradient(hsl(195deg, 100%, 78%), #a29bfe);
}
.brand--image--dark {
  background-image: linear-gradient(#040706, #a29bfe);
}
</style>