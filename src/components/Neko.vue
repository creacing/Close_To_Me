<template>
  <div id="neko" :class="[isSun ? 'dark' : '', isShow ? 'show--cartoon' : '']">
    <div class="planet">
      <div class="sun"></div>
      <div class="moon"></div>
    </div>
    <div class="body">
      <div class="face">
        <section class="eyes left">
          <span class="pupil"></span>
        </section>
        <section class="eyes right">
          <span class="pupil"></span>
        </section>
        <span class="nose"></span>
      </div>
    </div>
  </div>
</template>
<script setup>
import { defineProps, toRefs } from "vue";
const props = defineProps({ isSun: Boolean, isShow: Boolean });
const { isSun, isShow } = toRefs(props);
</script>
<style scoped lang="scss">
.show--cartoon {
  opacity: 1;
  display: block !important;
}
</style>