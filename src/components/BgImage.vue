

<template>
  <div class="brand-bg" :class="[isDark === 1 ? 'brand-img--white' : 'brand-img--dark']"></div>
</template>
<script setup>
import { watch } from "vue";
import { store } from "@/stores/store.js";
import { storeToRefs } from "pinia";
const { isDark } = storeToRefs(store());
</script>
<style scoped lang='scss'>
.brand-img--white {
  background-image: linear-gradient(hsl(195deg, 100%, 78%), #a29bfe);
}
.brand-img--dark {
  background-image: linear-gradient(#040706, #a29bfe);
}

.brand-bg {
  display: block;
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 70vh;
  min-height: 25rem;
  z-index: -9;
  background-color: #363636;
}

.brand-bg ::before {
  content: "";
  display: block;
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background-color: rgba(0, 0, 0, 0.2);
  z-index: 1;
  transition: all 0.2s ease-in-out 0s;
}

[data-theme="dark"] .brand-bg::before {
  background-color: rgba(0, 0, 0, 0.5);
}
</style>