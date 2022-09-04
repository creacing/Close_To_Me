

<template>
  <div class="inner">
    <div id="brand">
      <div class="pjax">
        <a href="/" class="logo" rel="start" data-pjax-state=""
          ><p class="artboard">{{ author }}</p>
          <h1 itemprop="name headline" class="title">{{ title }}</h1>
        </a>
        <p class="meta" itemprop="description">{{ description }}</p>
      </div>
    </div>
  </div>
</template>
<script setup>
import config from "../../public/config";
const { author, title, description } = config;
</script>

<style lang="scss" scoped>
#brand,
#brand .pjax {
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
}
#brand {
  position: fixed;
  padding: 3rem 5rem 0;
  text-align: center;
  width: 100%;
  height: 50vh;
  min-height: 10rem;
}
@media (max-width: 767px) {
  #brand {
    padding: 3rem 0.5rem 0;
  }
}
</style>

