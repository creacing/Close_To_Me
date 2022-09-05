

<template>
  <div class="inner">
    <div id="brand" :class="startScroll?'affix':''">
      <div class="pjax">
        <a href="/" class="logo" rel="start" data-pjax-state>
          <p class="artboard">{{ author }}</p>
          <h1 itemprop="name headline" class="title">{{ title }}</h1>
        </a>
        <p class="meta" itemprop="description">{{ description }}</p>
      </div>
    </div>
  </div>
</template>
<script setup>
import config from "../../public/config";
import { onMounted, ref } from 'vue'
const { author, title, description } = config;
const startScroll = ref(false)
onMounted(() => {
  window.addEventListener('scroll', () => {
    window.pageYOffset > 0 ?
      startScroll.value = true :
      startScroll.value = false
  })
})

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

