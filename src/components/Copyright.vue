<template>
  <div class="copywrite">
    <span class="sakura">
      <i class="ic i-sakura rotate"></i>
    </span>
    2019 –
    <span>{{ currentYear }}</span>
    <span class="sakura">
      <i class="ic i-sakura rotate"></i>
    </span>
    <span>{{ author }}</span>
  </div>
</template>
<script setup>
import config from './../../public/config.js'


const { author } = config;
const currentDate = new Date();
const currentYear = currentDate.getFullYear();
</script>
<style lang="scss" scoped>
.copywrite {
  width: 100%;
  text-align: center;
  margin: 1rem 0;
}
.sakura {
  color: hsl(350deg 100% 88%);
  display: inline-block;
  margin: 0 0.5rem;
}
</style>