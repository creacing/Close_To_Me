<template>
  <div id="loading" :class="[showLoading ? '' : 'show--loading']">
    <div class="cat">
      <div class="body"></div>
      <div class="head">
        <div class="face"></div>
      </div>
      <div class="foot">
        <div class="tummy-end"></div>
        <div class="bottom"></div>
        <div class="legs left"></div>
        <div class="legs right"></div>
      </div>
      <div class="paw">
        <div class="hands left"></div>
        <div class="hands right"></div>
      </div>
    </div>
  </div>
</template>
<script setup>
import { onMounted, ref, onBeforeMount } from "vue";
const showLoading = ref(false);
onBeforeMount(() => {
  showLoading.value = true;
});
onMounted(() => {
  window.onload = () => {
    showLoading.value = false;
  };
});
</script>

<style lang="scss" scoped>
.show--loading {
  display: none;
  opacity: 0;
}
</style>
